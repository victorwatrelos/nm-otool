/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_magic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_magic.h"

int				read_magic(t_file_info *file_info)
{
	uint32_t		magic;

	magic = uint32_t_from_bytes(file_info->data, 0, file_info->end);
	if (magic != MH_MAGIC_64 && magic != MH_CIGAM_64
			&& magic != MH_CIGAM && magic != MH_MAGIC
			&& magic != FAT_MAGIC && magic != FAT_CIGAM)
	{
		return (NOT_VALID);
	}
	file_info->header.magic = magic;
	file_info->is_64 = magic == MH_MAGIC_64 || magic == MH_CIGAM_64;
	file_info->swap_bytes = magic == MH_CIGAM
		|| magic == MH_CIGAM_64
		|| magic == FAT_CIGAM;
	file_info->is_fat = magic == FAT_MAGIC || magic == FAT_CIGAM;
	return (SUCCESS);
}
