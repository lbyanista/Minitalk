# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 10:50:14 by mlabrayj          #+#    #+#              #
#    Updated: 2021/06/17 11:20:48 by mlabrayj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./minitalk

SERVER = server

CLIENT = client

SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_atoi.c ft_isdigit.c ft_strlen.c \
		ft_strdup.c

# FLAGS = -Wall -Wextra -Werror

all:
	@gcc $(FLAGS) $(SRC) server.c -o $(SERVER)
	@gcc $(FLAGS) $(SRC) client.c -o $(CLIENT)

clean:
	@rm -rf $(SERVER) $(CLIENT) *dSYM *.gch

fclean: clean

re: fclean all