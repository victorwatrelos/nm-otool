/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_magic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAGIC_H
# define READ_MAGIC_H

# include <mach-o/loader.h>
# include <mach-o/fat.h>
# include "get_data_from_bytes_array.h"
# include "struct.h"
# include "define.h"

int				read_magic(t_file_info *file_info);

#endif
