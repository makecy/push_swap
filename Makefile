# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 18:22:16 by mstefano          #+#    #+#              #
#    Updated: 2024/02/27 03:03:12 by mstefano         ###   ########.fr        #
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
INCLUDES = -L ./libraries/Libft -lft

SRC = 	push_swap.c \
		operations.c \
		parse.c \
		libraries/ft_printf/ft_printf.c \
		libraries/get_next_line/get_next_line.c \

BONUS_SRC = checker.c \

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)


all : $(NAME) $(BONUS)

$(NAME): $(OBJ)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDES)

$(BONUS): $(BONUS_OBJ) $(OBJ)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(OBJ) -o $(BONUS) $(INCLUDES)

bonus: $(BONUS)
	
clean :
	rm -f $(OBJ) $(BONUS_OBJ) $(NAME) $(BONUS)
	@cd $(LIBFTDIR) && $(MAKE) clean
	
fclean : clean
	rm -f $(NAME)
	@cd $(LIBFTDIR) && $(MAKE) fclean

re : fclean all

.PHONY: all clean fclean re

