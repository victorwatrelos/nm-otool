/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_UTIL_H
# define MAIN_UTIL_H

# include <sys/types.h>
# include <sys/stat.h>
# include "struct.h"
# include "process_file.h"

void			free_file_info(t_file_info *file_info);
void			print_file_info(t_file_info *file_info);
t_file_info		*read_file(const int fd, const char *name,
		int (*fn)(t_file_info *, int));

#endif
