/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:51:46 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/10 17:07:26 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		ft_free_split(char **str)
{
	free (str[0]);
	free (str);
	str = NULL;
}

void		ft_free_rooms(t_rooms *rooms)
{
	t_rooms		*temp;
	t_rooms		*cpy;

	while (temp)
	{
		cpy = temp;
		temp = temp->next;
		free (cpy->name);
		free (cpy);
		cpy = NULL;
	}


}
