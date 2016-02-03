/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_fat.h"

void			process_fat(t_file_info *file_info)
{
	struct fat_header	*fat;
	struct fat_arch		*arch;
	uint32_t			n;
	uint32_t			offset;
	t_file_info			sub_file_info;

	fat = file_info->data;
	n = fat->nfat_arch;
	n = swapuint32_t(n);
	arch = file_info->data + sizeof(fat);
	while (n)
	{
		if (swapuint32_t(arch->cputype) == CPU_TYPE_X86_64)
			offset = arch->offset;
		arch += sizeof(arch) / sizeof(void*);
		n--;
	}
	ft_memcpy(&sub_file_info, file_info, sizeof(t_file_info));
	sub_file_info.data = file_info->data + swapuint32_t(offset);
	process_file(&sub_file_info, FALSE);
}
