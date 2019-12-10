/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:04:04 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/10 20:43:11 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int				read_file(int fd, char **line)
{
	int			gnl;


	if ((gnl = get_next_line(fd, line)) == -1)
		ft_error("Error reading");
	return (gnl);
}

int				parse_ants(char *line)
{
	int			i;
	int			ants;

	i = 0;
	while(line[i])
	{
		if (ft_isdigit(line[i]))
			i++;
		else
			ft_error("Error map in ants");
	}
	ants = ft_atoi(line);
	free(line);
	if (ants == 0)
		ft_error("Error map in ants");	
	return (ants);
}

int				check_comment(char *line)
{
	if (ft_strcmp(line, "#") == 0)
		return (-1);
	else if (line[0] == '#' && line[1] == '#' && (ft_strcmp(line + 2, "start") != 0  && ft_strcmp(line + 2, "end") != 0))
		return (-1);
	return (1);
}

int				ft_hash(char *line)
{
	if (check_comment(line) == -1)
	{
		ft_error("Error in comment 2");
		return (-3);
	}
	else if (line[0] == '#' && line[1] != '#')
		return (-1);
	else if (ft_strcmp(line, "##start") == 0)
		return (1);
	else if (ft_strcmp(line, "##end") == 0)
		return (2);
	else
		return (0);
}

void			parse_file(int fd, t_lem_in *lem_in)
{
	char		*line;

	read_file(fd, &line);
	lem_in->ants = parse_ants(line);
	line = parse_rooms(fd, line, lem_in); 
	valid_rooms2(lem_in);
	parse_links(fd, line, lem_in);
	t_rooms *temp;
	temp = lem_in->rooms;
	while (temp)
	{
		if (temp->type == 1)
			printf("start ");
		if (temp->type == 2)
			printf("end ");
		printf("%s %d %d\n", temp->name, temp->x, temp->y);
		temp = temp->next;
	}
	printf ("%s\n", line);
	ft_free_rooms(lem_in->rooms);
}
