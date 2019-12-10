/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:50:34 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/10 20:22:13 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		ft_error(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	int				fd;
	t_lem_in		lem_in;

	if (ac != 2)
		ft_error("Usage : ./lem-in <filename>\n");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error("Open error");
	parse_file(fd, &lem_in);
	if (close(fd) < 0)
		ft_error("Close error");
	return (0);
}
