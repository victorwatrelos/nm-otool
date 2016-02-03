/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_segment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_segment.h"

static t_section_info	*add_section(struct section *sect)
{
	t_section_info		*section;

	section = malloc(sizeof(t_section_info));
	if (section == NULL)
		return (NULL);
	ft_memcpy(section->segname, sect->segname, sizeof(char) * 16);
	ft_memcpy(section->sectname, sect->sectname, sizeof(char) * 16);
	section->size = sect->size;
	return (section);
}

static int				process_sections(t_file_info *file_info,
		struct segment_command *seg, size_t cmd_offset)
{
	uint32_t			i;
	size_t				offset;
	t_section_info		*section;

	i = 0;
	offset = cmd_offset + sizeof(struct segment_command);
	while (i < seg->nsects)
	{
		section = add_section(file_info->data + offset);
		ft_lstadd(&(file_info->lst_sections),
				ft_lstnew(section, sizeof(t_section_info)));
		offset += sizeof(struct section);
		i++;
	}
	return (SUCCESS);
}

int						process_segment(t_file_info *file_info,
		size_t cmd_offset)
{
	struct segment_command	*seg;

	seg = file_info->data + cmd_offset;
	file_info->segment_command[file_info->nb_segment_cmd] = *seg;
	file_info->nb_segment_cmd++;
	process_sections(file_info, seg, cmd_offset);
	return (SUCCESS);
}
