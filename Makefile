# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 18:22:16 by mstefano          #+#    #+#              #
#    Updated: 2024/02/26 02:28:11 by mstefano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libraries/Libft
OBJ_DIR = obj
BONUS = checker
SRC_DIR = srcs

SRC = 	push_swap.c \
		operations.c \
		parse.c \

BONUS_SRC = checker.c \

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)


all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	
clean :
	rm -f $(OBJ)
	
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

