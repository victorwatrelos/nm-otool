/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_cmd.h"

static int			read_header(t_file_info *file_info)
{
	ft_memcpy(&(file_info->header),
			file_info->data, sizeof(struct mach_header));
	return (SUCCESS);
}

static size_t		process_cmd(size_t cmd_offset, t_file_info *file_info)
{
	struct load_command	cmd;

	if (!ft_maxmemcpy(&cmd,
			file_info->data + cmd_offset,
			sizeof(struct load_command),
			file_info->end))
	{
		return (0);
	}
	if (cmd.cmd == LC_SEGMENT)
	{
		process_segment(file_info, cmd_offset);
	}
	if (cmd.cmd == LC_SYMTAB)
	{
		process_symtab(file_info, cmd_offset);
	}
	return (cmd.cmdsize);
}

static int			load_cmd(t_file_info *file_info)
{
	size_t				load_cmd_offset;
	uint32_t			i;

	load_cmd_offset = sizeof(struct mach_header);
	i = 0;
	while (i < file_info->header.ncmds)
	{
		load_cmd_offset += process_cmd(load_cmd_offset, file_info);
		i++;
	}
	return (SUCCESS);
}

int					load(t_file_info *file_info)
{
	read_header(file_info);
	load_cmd(file_info);
	return (SUCCESS);
}
