/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fat.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_FAT_H
# define PROCESS_FAT_H

# include "struct.h"
# include <mach-o/fat.h>
# include "util.h"
# include "process_file.h"

void	process_fat(t_file_info *file_info);
typedef struct fat_header	t_fat_header;
typedef struct fat_arch		t_fat_arch;

#endif
