/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_symtab.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_SYMTAB_H
# define PROCESS_SYMTAB_H

# include "struct.h"
# include "define.h"
# include "libft.h"
# include "puthexa.h"
# include "util.h"
# include "ft_printf.h"
# include "process_symtab_util.h"
# include "process_symtab_util_64.h"

int			process_symtab(t_file_info *file_info, size_t offset);
int			process_symtab_64(t_file_info *file_info, size_t offset);

#endif
