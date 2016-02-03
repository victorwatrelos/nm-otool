/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_symtab_util_64.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_symtab_util_64.h"

static t_section_info	*find_sect(uint8_t n_sect, t_file_info *file_info)
{
	t_list	*list;
	size_t	i;

	i = 1;
	list = file_info->lst_sections;
	while (list != NULL)
	{
		if (i == n_sect)
			return (list->content);
		list = list->next;
		i++;
	}
	return (NULL);
}

static char				get_char_sect_type(char *sectname)
{
	if (!ft_strcmp(sectname, SECT_TEXT))
		return ('T');
	if (!ft_strcmp(sectname, SECT_BSS))
		return ('B');
	if (!ft_strcmp(sectname, SECT_DATA))
		return ('D');
	return ('S');
}

int						process_n_sect_64(t_symbol_info *sym_info,
		t_file_info *file_info, struct nlist_64 *symbol)
{
	t_section_info	*sect;

	sect = find_sect(symbol->n_sect, file_info);
	if (!sect)
		return (NOT_VALID);
	sym_info->type = get_char_sect_type(sect->sectname);
	return (SUCCESS);
}
