/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_file.h"

static int			is_ar(void *data, void *max)
{
	if (max <= data + SARMAG)
	{
		return (FALSE);
	}
	if (!ft_strncmp(data, ARMAG, SARMAG))
	{
		return (TRUE);
	}
	return (FALSE);
}

static void			clean(t_file_info *file_info)
{
	dellst(&(file_info->lst_sections));
}

int					send_data(t_file_info *file_info)
{
	if (is_ar(file_info->data, file_info->end))
	{
		process_ar(file_info);
		return (SUCCESS);
	}
	if (read_magic(file_info))
	{
		return (NOT_VALID);
	}
	if (file_info->is_fat)
	{
		file_info->display = 16;
		process_fat(file_info);
		return (SUCCESS);
	}
	if (file_info->is_64)
	{
		file_info->display = 16;
		load_64(file_info);
		return (SUCCESS);
	}
	load(file_info);
	return (SUCCESS);
}

int					process_file(t_file_info *file_info, int first)
{
	int ret;

	(void)first;
	ret = send_data(file_info);
	clean(file_info);
	return (ret);
}
