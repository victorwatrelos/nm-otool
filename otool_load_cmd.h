/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_load_cmd.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_LOAD_CMD_H
# define OTOOL_LOAD_CMD_H

# include "struct.h"
# include "define.h"
# include "otool_segment_64.h"

int					otool_load_64(t_file_info *file_info);
int					otool_load(t_file_info *file_info);

#endif
