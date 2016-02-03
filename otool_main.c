/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool_main.h"

static int			otool_first(t_file_info *file_info, int useless)
{
	(void)useless;
	return (otool(file_info, TRUE));
}

static int			otool_file(char *name)
{
	t_file_info		*file_info;
	int				fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("error: %s unable to open\n", name);
		return (1);
	}
	if (!(file_info = read_file(fd, name, otool_first)))
	{
		close(fd);
		return (1);
	}
	close(fd);
	free_file_info(file_info);
	return (0);
}

int					main(int argc, char **argv)
{
	int				i;

	if (argc < 2)
	{
		ft_printf("%s filename\n", argv[0]);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		otool_file(argv[i]);
		i++;
	}
	return (0);
}
