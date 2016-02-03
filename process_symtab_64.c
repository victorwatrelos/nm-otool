/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_symtab_64.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_symtab.h"

static char	get_char_rep(uint8_t n_type)
{
	if (n_type == N_UNDF)
		return (CHAR_UNDF);
	if (n_type == N_ABS)
		return (CHAR_ABS);
	if (n_type == N_INDR)
		return (CHAR_INDR);
	return (CHAR_NOT_FOUND);
}

static int	process_symbols(t_file_info *file_info,
		uint64_t stroff,
		struct nlist_64 *symbol)
{
	uint8_t			n_type;
	t_symbol_info	*sym_info;

	sym_info = malloc(sizeof(t_symbol_info));
	if (symbol->n_type & N_STAB)
	{
		free(sym_info);
		return (SUCCESS);
	}
	n_type = symbol->n_type & N_TYPE;
	sym_info->type = get_char_rep(n_type);
	sym_info->name = file_info->data + stroff + symbol->n_un.n_strx;
	sym_info->n_value = symbol->n_value;
	sym_info->undf = (n_type == N_UNDF);
	if (n_type == N_SECT)
		process_n_sect_64(sym_info, file_info, symbol);
	if (!(symbol->n_type & N_EXT))
		sym_info->type = ft_tolower(sym_info->type);
	ft_lstsortadd(&(file_info->lst_symbols),
			ft_lstnew(sym_info, sizeof(t_symbol_info)));
	return (SUCCESS);
}

static void	*display_sym(void *data)
{
	t_symbol_info	*sym_info;
	char			*str;
	int				i;

	i = 0;
	sym_info = (t_symbol_info *)data;
	if (!(str = puthexa(sym_info->n_value)))
		return (data);
	if (sym_info->undf)
	{
		ft_printf("                 %c %s\n", sym_info->type, sym_info->name);
		free(str);
		return (data);
	}
	ft_printf("%s %c %s\n", str, sym_info->type, sym_info->name);
	free(str);
	return (data);
}

int			process_symtab_64(t_file_info *file_info, size_t offset)
{
	struct symtab_command	symtab_cmd;
	struct nlist_64			*symbols;
	size_t					i;

	ft_memcpy(&symtab_cmd, file_info->data + offset,
			sizeof(struct symtab_command));
	symbols = (struct nlist_64 *)(file_info->data + symtab_cmd.symoff);
	i = 0;
	while (i < symtab_cmd.nsyms)
		process_symbols(file_info, symtab_cmd.stroff, symbols + i++);
	ft_lstiter(file_info->lst_symbols, display_sym);
	dellst(&(file_info->lst_symbols));
	return (SUCCESS);
}
