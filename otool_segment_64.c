/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_segment_64.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool_segment_64.h"

static void			print_sect(uint64_t addr, uint64_t size, void *data)
{
	uint32_t	i;
	char		*str;
	uint8_t		oct;

	i = 0;
	while (i < size)
	{
		if (!(i % 16))
		{
			if (i != 0)
			{
				addr += 16;
				ft_printf("\n");
			}
			str = puthexa(addr);
			ft_printf("%s ", str);
			free(str);
		}
		oct = ((uint8_t *)data)[i];
		str = puthexa(oct);
		ft_printf("%s ", str + 14);
		free(str);
		i++;
	}
	ft_printf("\n");
}

static void			add_section(struct section_64 *sect, t_file_info *file_info)
{
	if (!ft_strcmp(sect->segname, SEG_TEXT)
			&& !ft_strcmp(sect->sectname, SECT_TEXT))
	{
		ft_printf("(__TEXT,__text) section\n");
		if (sect->size > 0)
			print_sect(sect->addr, sect->size, file_info->data + sect->offset);
	}
}

static int			process_sections(t_file_info *file_info,
		struct segment_command_64 *seg, size_t cmd_offset)
{
	uint32_t			i;
	size_t				offset;

	i = 0;
	offset = cmd_offset + sizeof(struct segment_command_64);
	while (i < seg->nsects)
	{
		add_section(file_info->data + offset, file_info);
		offset += sizeof(struct section_64);
		i++;
	}
	return (SUCCESS);
}

int					otool_segment_64(t_file_info *file_info, size_t cmd_offset)
{
	struct segment_command_64	*seg;

	seg = file_info->data + cmd_offset;
	file_info->segment_command_64[file_info->nb_segment_cmd] = *seg;
	file_info->nb_segment_cmd++;
	process_sections(file_info, seg, cmd_offset);
	return (SUCCESS);
}
