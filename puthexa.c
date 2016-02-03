/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puthexa.h"

static char	get_char(char val)
{
	char binding[6];

	binding[0] = 'a';
	binding[1] = 'b';
	binding[2] = 'c';
	binding[3] = 'd';
	binding[4] = 'e';
	binding[5] = 'f';
	if (val < 10)
		return (val + '0');
	if (val > 15)
		return ('Z');
	return (binding[val - 10]);
}

static int	calc_i(uint64_t n)
{
	int		i;

	i = 0;
	while (n > 15)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*get_str(void)
{
	char	*str;
	int		i;

	if (!(str = ft_strnew(16)))
		return (NULL);
	i = 0;
	while (i < 15)
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

char		*puthexa(uint64_t val)
{
	char	tmp;
	int		i;
	int		n;
	char	*res;

	i = calc_i(val);
	if (i > 16)
		return (NULL);
	if (!(res = get_str()))
		return (NULL);
	n = 15 - i;
	while (i >= 0)
	{
		tmp = val % 16;
		res[i + n] = get_char(tmp);
		val /= 16;
		i--;
	}
	return (res);
}
