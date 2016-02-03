/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_from_bytes_array.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_DATA_FROM_BYTES_ARRAY_H
# define GET_DATA_FROM_BYTES_ARRAY_H

# include <stdint.h>
# include <stddef.h>

uint32_t	uint32_t_from_bytes(void *data, size_t pos, void *max);

#endif
