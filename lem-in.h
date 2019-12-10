/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:23:00 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/10 20:47:56 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEMIN_H
# define LEMIN_H

# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct              s_rooms
{
	char					*name;
	int						x;
	int						y;
	int						type;	// 0 - middle, 1 - start, 2 - end,
	struct s_rooms			*next;
}							t_rooms;

typedef struct				s_lem_in
{
	int						ants;
	t_rooms					*rooms;
	t_rooms					*start;
	t_rooms					*end;
}							t_lem_in;

void						ft_error(char *str);


void            parse_file(int fd, t_lem_in *lem_in);
int             parse_ants(char *line);
char            *parse_rooms(int fd, char *line, t_lem_in *lem_in);
void			parse_links(int fd, char *line, t_lem_in *lem_in);
int	            read_file(int fd, char **line);
int             ft_hash(char *line);
void			ft_free_split(char **str);
void			ft_free_rooms(t_rooms *rooms);
void			valid_rooms2(t_lem_in *lem_in);


# endif
