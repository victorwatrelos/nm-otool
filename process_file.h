/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_FILE_H
# define PROCESS_FILE_H

# include <mach-o/loader.h>
# include <mach-o/fat.h>
# include "struct.h"
# include "define.h"
# include "load_cmd.h"
# include "get_data_from_bytes_array.h"
# include "process_ar.h"
# include "process_fat.h"
# include "libft.h"
# include "read_magic.h"

int		process_file(t_file_info *file_info, int first);
int		read_magic(t_file_info *file_info);

#endif
