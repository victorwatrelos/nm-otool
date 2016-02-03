/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 13:59:29 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:30:18 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t				i;
	unsigned char		*ptr;

	if (s == NULL)
		return ;
	i = 0;
	ptr = (unsigned char*)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
