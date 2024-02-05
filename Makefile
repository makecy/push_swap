# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 18:22:16 by mstefano          #+#    #+#              #
#    Updated: 2024/02/02 17:03:10 by mstefano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	
clean :
	rm -f $(OBJ)
	
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

