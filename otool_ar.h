/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_ar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_AR_H
# define OTOOL_AR_H

# include "struct.h"
# include "process_file.h"
# include <libft.h>
# include <ft_printf.h>
# include <ar.h>
# include <mach-o/ranlib.h>
# include "otool_main.h"

typedef struct ar_hdr	t_ar_hdr;
typedef struct ranlib	t_ranlib;

void	otool_ar(t_file_info *file_info);

#endif
