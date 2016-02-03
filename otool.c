/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

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

static int			otool_manage_ar(t_file_info *file_info, int first)
{
	if (is_ar(file_info->data, file_info->end))
	{
		if (first)
			ft_printf("Archive : %s\n", file_info->name);
		otool_ar(file_info);
		return (TRUE);
	}
	return (FALSE);
}

int					otool(t_file_info *file_info, int first)
{
	uint32_t	magic;

	if (otool_manage_ar(file_info, first))
		return (SUCCESS);
	magic = *(uint32_t *)file_info->data;
	if (read_magic(file_info) == NOT_VALID)
	{
		ft_printf("%s: is not an object file\n", file_info->name);
		return (NOT_VALID);
	}
	else if (file_info->is_64)
	{
		if (first)
			ft_printf("%s:\n", file_info->name);
		otool_load_64(file_info);
	}
	else if (file_info->is_fat)
		otool_fat(file_info);
	else
	{
		if (first)
			ft_printf("%s:\n", file_info->name);
		otool_load(file_info);
	}
	return (SUCCESS);
}
