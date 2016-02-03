/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_ar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool_ar.h"

static int			get_size(char *str)
{
	char	*str_part;

	str_part = ft_strchr(str, '/') + 1;
	return (ft_atoi(str_part));
}

static void			print_ar(uint32_t off, t_file_info *file_info)
{
	int				size;
	char			*name;
	struct ar_hdr	*ar;
	t_file_info		sub_file_info;

	ar = file_info->data + off;
	name = ft_strstr(ar->ar_name, ARFMAG) + ft_strlen(ARFMAG);
	size = get_size(ar->ar_name);
	ft_printf("%s(%s):\n", file_info->name, name);
	ft_memcpy(&sub_file_info, file_info, sizeof(t_file_info));
	sub_file_info.data = (void *)ar + sizeof(*ar) + size;
	otool(&sub_file_info, FALSE);
}

static void			browse_lst(t_list *list, t_file_info *file_info)
{
	t_list		*next;

	while (list != NULL)
	{
		print_ar(*((uint32_t *)list->content), file_info);
		next = list->next;
		free(list->content);
		free(list);
		list = next;
	}
}

static void			browse_ar(struct ranlib *ran, int size,
		t_file_info *file_info)
{
	int			i;
	t_list		*list;
	uint32_t	*off;

	list = NULL;
	i = 0;
	while (i < size)
	{
		off = malloc(sizeof(uint32_t));
		*off = ran[i].ran_off;
		ft_lstsortbyoffadd(&list, ft_lstnew(off, sizeof(uint32_t)));
		i++;
	}
	browse_lst(list, file_info);
}

void				otool_ar(t_file_info *file_info)
{
	t_ar_hdr		*ar;
	t_ranlib		*ranlib;
	size_t			size;
	int				nb_obj_file;
	void			*pos;

	pos = file_info->data + sizeof(struct ar_hdr) + SARMAG;
	ar = file_info->data + SARMAG;
	size = get_size(ar->ar_name);
	nb_obj_file = *(int *)(pos + size);
	ranlib = file_info->data + sizeof(*ar) + SARMAG + size + 4;
	browse_ar(ranlib, nb_obj_file / sizeof(struct ranlib), file_info);
}
