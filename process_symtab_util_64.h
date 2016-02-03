/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_symtab_util_64.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_SYMTAB_UTIL_64_H
# define PROCESS_SYMTAB_UTIL_64_H

# include "struct.h"
# include "define.h"
# include "libft.h"
# include <mach-o/nlist.h>

int					process_n_sect_64(t_symbol_info *sym_info,
		t_file_info *file_info, struct nlist_64 *symbol);

#endif
