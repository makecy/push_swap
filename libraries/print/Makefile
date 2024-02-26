# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 15:18:11 by mstefano          #+#    #+#              #
#    Updated: 2024/02/11 23:07:55 by mstefano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRC = ft_print_character.c ft_printf.c ft_print_formats.c ft_print_ptr.c ft_print_str.c\
	  ft_print_decimal.c ft_print_percent.c ft_print_unsigneddecimal.c ft_print_hexa.c\
	  
OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all : $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
