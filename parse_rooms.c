/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:04:04 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/10 19:37:56 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void				check_L_or_hash_in_name(char c)
{
	if (c == 'L')
		ft_error("Error - Name begins whith L");
	if (c == '#')
		ft_error("Error - Name begins whith #");
}

static char			**valid_rooms(char *line)
{
	char **str;
	int i;
	int j;

	i = 0;
	j = 1;
	str = ft_strsplit(line, ' ');
	while (str[i] != NULL)
		i++;
	if (i != 3)
	{
		ft_free_split(str);
		return( NULL); 
	}
	while (j < 3)
	{
		i = 0;
		while (str[j][i])
		{
			if (ft_isdigit(str[j][i]) || str[j][0] == '-')
				i++;
			else
			{
				ft_free_split(str);
				return (NULL);
			}
		}
		j++;
	}
	check_L_or_hash_in_name(str[0][0]);
	return (str);
}

t_rooms			*creat_room(char **str, int type)
{
	t_rooms		*new;
	
	if ((new = (t_rooms *)malloc(sizeof(t_rooms))) == NULL)
		ft_error("error of malloc");
	new->name = ft_strjoin("", str[0]);
	new->x = ft_atoi(str[1]);
	new->y = ft_atoi(str[2]);
	new->type = type;
	new->next = NULL;
	new->type = type;
	return (new);
}

void			add_room(t_lem_in *lem_in, char *line, int type)
{
	char		**str;
	t_rooms		*cpy;
	t_rooms		*p;

	cpy = lem_in->rooms;
	if ((str = valid_rooms(line)) == NULL)
		ft_error("Error in room");
	free(line);
	if (lem_in->rooms == NULL)
	{
			lem_in->rooms = creat_room(str, type);
			p = lem_in->rooms;
	}
	else
	{
		while(cpy->next != NULL)
			cpy = cpy->next;
		cpy->next = creat_room(str, type);
		p = cpy->next;
	}
	ft_free_split(str);
}

void			add_start_end_room(t_lem_in *lem_in, char *line, int type, int fd)
{
	int			gnl;

	free (line);
	if ((gnl = read_file(fd, &line)) > 0)
		add_room(lem_in, line, type);
	else
		ft_error("Error in start or end room");
}	

char			*parse_rooms(int fd, char *line, t_lem_in *lem_in)
{
	int			gnl;
	t_rooms		rooms;
	int type;

	while ((gnl = read_file(fd, &line)) > 0)
	{
		type = ft_hash(line);
		if (type == -1 && valid_rooms(line) == NULL)
		{
			free(line);
			continue ;
		}
		else if (type == 1)
			add_start_end_room(lem_in, line, type, fd);
		else if (type == 2)
			add_start_end_room(lem_in, line, type, fd);
		else if (type == 0 && valid_rooms(line) != NULL)
			add_room(lem_in, line, type);
		else break ;
	}
	return (line);
}
