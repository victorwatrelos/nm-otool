/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

size_t			ft_strmaxlen(char *str, void *max)
{
	size_t i;

	i = 0;
	while (str != max && *(str++) != '\0')
		i++;
	return (i);
}

int				ft_strmaxcmp(const char *s1, const char *s2, void *max)
{
	while (s1 != max && s2 != max && *s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void			dellst(t_list **begin)
{
	t_list	*list;
	t_list	*next;

	list = *begin;
	while (list != NULL)
	{
		next = list->next;
		free(list->content);
		free(list);
		list = next;
	}
	*begin = NULL;
}

int				ft_maxmemcpy(void *dst, void *src, size_t size, void *max)
{
	if (src + size >= max)
	{
		return (FALSE);
	}
	ft_memcpy(dst, src, size);
	return (TRUE);
}

uint32_t		swapuint32_t(uint32_t val)
{
	uint32_t	res;

	res = ((val >> 24) & 0xff)
			| ((val << 8) & 0xff0000)
			| ((val >> 8) & 0xff00)
			| ((val << 24) & 0xff000000);
	return (res);
}
