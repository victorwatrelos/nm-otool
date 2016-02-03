/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stddef.h>
# include "list.h"
# include "struct.h"
# include "libft.h"

size_t		ft_strmaxlen(char *str, void *max);
int			ft_strmaxcmp(const char *s1, const char *s2, void *max);
void		ft_lstsortadd(t_list **begin, t_list *new_elem);
int			ft_maxmemcpy(void *dst, void *src, size_t size, void *max);
void		dellst(t_list **begin);
uint32_t	swapuint32_t(uint32_t val);
void		ft_lstsortbyoffadd(t_list **begin, t_list *new_elem);

#endif
