# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 15:52:49 by lcutjack          #+#    #+#              #
#    Updated: 2019/12/10 20:53:01 by wtorwold         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = parse.c lem-in.c parse_rooms.c ft_free.c valid_rooms.c parse_link.c
OBJ = $(SRC:.c=.o)
INC = lem-in.h

all: game

game: $(OBJ) $(OBJM)
	@make -C libft/
	@gcc $(OBJ) -I $(INC) -L. libft/libft.a -o lem-in

clean:
	@make fclean -C libft/
	@rm -rf *.o

fclean: clean
	@rm -rf ./lem-in

re: fclean all
