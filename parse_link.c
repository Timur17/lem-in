/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:43:35 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/10 21:19:17 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			check_incorrect_chars(char *line)
{
	int 		i;

	i = 0;
	while (line[i + 1])
	{
		if (line[i] == '-' && line[i + 1] == '-')
			ft_error("Error charecter in links");
		i++;
	}

}

char			**valid_links(char *line)
{
	char		**str;
	int			i;
	int			j;

	i = 0;
	check_incorrect_chars(line);
	str = ft_strsplit(line, '-');
	free(line);
	while (str[i] != NULL)
		i++;
	if (i != 2)
	{
		ft_free_split(str);
		ft_error("Error in link");
		return (NULL);
	}
	return (str);
}

void			parse_links(int fd, char *line, t_lem_in *lem_in)
{
	int			gnl;

	gnl = 0;
	valid_links(line);
	printf ("%s\n", line);
	while ((gnl = read_file(fd, &line)) > 0)
	{
		printf ("%s\n", line);
		valid_links(line);
	}
}
