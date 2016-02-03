/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_segment.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_SEGMENT_H
# define PROCESS_SEGMENT_H

# include "struct.h"
# include "define.h"
# include "libft.h"

int	process_segment_64(t_file_info *file_info, size_t cmd_offset);
int	process_segment(t_file_info *file_info, size_t cmd_offset);

#endif
