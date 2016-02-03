/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_load_cmd_64.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool_load_cmd.h"

static int			read_header_64(t_file_info *file_info)
{
	ft_memcpy(&(file_info->header_64), file_info->data,
			sizeof(struct mach_header_64));
	return (SUCCESS);
}

static size_t		process_cmd_64(size_t cmd_offset, t_file_info *file_info)
{
	struct load_command	cmd;

	ft_memcpy(&cmd,
			file_info->data + cmd_offset,
			sizeof(struct load_command));
	if (cmd.cmd == LC_SEGMENT_64)
	{
		otool_segment_64(file_info, cmd_offset);
	}
	return (cmd.cmdsize);
}

static int			load_cmd_64(t_file_info *file_info)
{
	size_t				load_cmd_offset;
	uint32_t			i;

	load_cmd_offset = sizeof(struct mach_header_64);
	i = 0;
	while (i < file_info->header_64.ncmds)
	{
		load_cmd_offset += process_cmd_64(load_cmd_offset, file_info);
		i++;
	}
	return (SUCCESS);
}

int					otool_load_64(t_file_info *file_info)
{
	read_header_64(file_info);
	load_cmd_64(file_info);
	return (SUCCESS);
}
