/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static void		finish_sort(t_list *prec, t_list *new_elem, t_list **begin,
		t_list *list)
{
	if (prec == NULL)
	{
		new_elem->next = list;
		*begin = new_elem;
		return ;
	}
	prec->next = new_elem;
	new_elem->next = list;
}

void			ft_lstsortbyoffadd(t_list **begin, t_list *new_elem)
{
	t_list			*list;
	t_list			*prec;
	uint32_t		*current_sym_info;
	uint32_t		*next_sym_info;

	if (*begin == NULL)
	{
		*begin = new_elem;
		return ;
	}
	current_sym_info = new_elem->content;
	list = *begin;
	next_sym_info = list->content;
	prec = NULL;
	while (*current_sym_info > *next_sym_info)
	{
		prec = list;
		list = list->next;
		if (list == NULL)
			break ;
		next_sym_info = list->content;
	}
	finish_sort(prec, new_elem, begin, list);
}

void			ft_lstsortadd(t_list **begin, t_list *new_elem)
{
	t_list			*list;
	t_list			*prec;
	t_symbol_info	*current_sym_info;
	char			*current_str;
	t_symbol_info	*next_sym_info;

	if (*begin == NULL)
	{
		*begin = new_elem;
		return ;
	}
	current_sym_info = new_elem->content;
	current_str = current_sym_info->name;
	list = *begin;
	next_sym_info = list->content;
	prec = NULL;
	while (ft_strcmp(next_sym_info->name, current_str) < 0)
	{
		prec = list;
		list = list->next;
		if (list == NULL)
			break ;
		next_sym_info = list->content;
	}
	finish_sort(prec, new_elem, begin, list);
}
