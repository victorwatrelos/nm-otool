/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_util.h"

static int		get_file_data(const int fd, void *buff, size_t size)
{
	size_t		readed;
	ssize_t		ret;

	readed = 0;
	while (readed < size)
	{
		if (size < readed)
			return (-1);
		if (!(ret = read(fd, buff + readed, size - readed)))
			break ;
		if (ret < 0)
			return (-1);
		readed += ret;
	}
	return (0);
}

t_file_info		*read_file(const int fd, const char *name,
		int (*fn)(t_file_info *, int))
{
	struct stat		fstat_res;
	t_file_info		*file_info;

	file_info = malloc(sizeof(t_file_info));
	bzero(file_info, sizeof(t_file_info));
	if (fstat(fd, &fstat_res))
	{
		return (NULL);
	}
	file_info->size = (size_t)fstat_res.st_size;
	file_info->name = strdup(name);
	file_info->data = malloc(sizeof(char) * file_info->size);
	if (file_info->data == NULL)
	{
		return (NULL);
	}
	file_info->end = file_info->data + file_info->size;
	get_file_data(fd, file_info->data, file_info->size);
	fn(file_info, FALSE);
	return (file_info);
}

void			print_file_info(t_file_info *file_info)
{
	ft_printf("Is 64: %d\n", file_info->is_64);
	ft_printf("swap bytes: %d\n", file_info->swap_bytes);
	ft_printf("is fat: %d\n", file_info->is_fat);
}

void			free_file_info(t_file_info *file_info)
{
	free(file_info->name);
	free(file_info->data);
	free(file_info);
}
