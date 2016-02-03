/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:42:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/02/03 18:42:06 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		run_on_file(char *name, int argc)
{
	int				fd;
	t_file_info		*file_info;

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("error: %s unable to open\n", name);
		return (1);
	}
	if (argc > 2)
		ft_printf("\n%s:\n", name);
	if (!(file_info = read_file(fd, name, process_file)))
	{
		close(fd);
		return (1);
	}
	close(fd);
	free_file_info(file_info);
	return (0);
}

int				main(int argc, char **argv)
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
		run_on_file(argv[i], argc);
		i++;
	}
	return (0);
}
