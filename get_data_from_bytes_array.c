/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_from_bytes_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_data_from_bytes_array.h"

uint32_t	uint32_t_from_bytes(void *data, size_t pos, void *max)
{
	if (data + pos >= max)
	{
		return (0xFFFFFFFF);
	}
	return (*((uint32_t *)(data + pos)));
}
