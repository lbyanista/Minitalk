# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 10:50:14 by mlabrayj          #+#    #+#              #
#    Updated: 2021/06/22 15:27:26 by mlabrayj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server

CLIENT = client

SERVER_BONUS = server_bonus

CLIENT_BONUS = client_bonus

SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_atoi.c ft_isdigit.c ft_strlen.c \
		ft_strdup.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER):
	@gcc -I $(FLAGS) $(SRC) server.c -o $(SERVER)

$(CLIENT):
	@gcc -I $(FLAGS) $(SRC) client.c -o $(CLIENT)

$(SERVER_BONUS):
	@gcc -I $(FLAGS) $(SRC) minitalk_bonus/server_bonus.c -o $(SERVER_BONUS)

$(CLIENT_BONUS):
	@gcc -I $(FLAGS) $(SRC) minitalk_bonus/client_bonus.c -o $(CLIENT_BONUS)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

clean:
	@rm -rf *dSYM *.gch

fclean: clean
	@rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all