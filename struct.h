/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <unistd.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include "list.h"

typedef struct					s_symbol_info
{
	char						*name;
	char						type;
	uint64_t					n_value;
	char						undf;
	int							display;
}								t_symbol_info;

typedef struct					s_section_info
{
	char						sectname[16];
	char						segname[16];
	size_t						size;
}								t_section_info;

typedef struct mach_header			t_mach_header;
typedef struct mach_header_64		t_mach_header_64;
typedef struct segment_command		t_segment_command;
typedef struct segment_command_64	t_segment_command_64;

typedef struct					s_file_info
{
	size_t						size;
	void						*end;
	char						*name;
	void						*data;
	char						is_64;
	char						is_fat;
	char						swap_bytes;
	t_mach_header				header;
	t_mach_header_64			header_64;
	t_segment_command			segment_command[MAX_SECT];
	t_segment_command_64		segment_command_64[MAX_SECT];
	size_t						nb_segment_cmd;
	int							display;
	t_list						*lst_symbols;
	t_list						*lst_sections;
}								t_file_info;

#endif
