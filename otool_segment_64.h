/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_segment_64.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_SEGMENT_64_H
# define OTOOL_SEGMENT_64_H

# include "struct.h"
# include "define.h"
# include "puthexa.h"
# include <ft_printf.h>

int		otool_segment_64(t_file_info *file_info, size_t cmd_offset);
int		otool_segment(t_file_info *file_info, size_t cmd_offset);

#endif
