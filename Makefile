# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 10:50:14 by mlabrayj          #+#    #+#              #
#    Updated: 2021/06/11 14:10:19 by mlabrayj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./server

SRC = server.c client.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
		@gcc $(SRC) $(FLAGS) -o $(NAME)

clean:
	@rm -rf $(NAME) *dSYM *.gch

fclean: clean

re: fclean all