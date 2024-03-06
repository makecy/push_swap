# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 18:22:16 by mstefano          #+#    #+#              #
#    Updated: 2024/03/06 16:33:52 by mstefano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBRARIES_PATH = ./libraries
LIBRARIES = $(LIBRARIES_PATH)/libraries.a


SRC = 	push_swap.c \
		operations.c \
		operations1.c \
		operations2.c \
		sorting.c \
		creatingstack.c \
		error_message.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBRARIES):
	make -C $(LIBRARIES_PATH)

$(NAME): $(LIBRARIES) $(OBJ)  
	@cc $(CFLAGS) $(LIBRARIES) -o $(NAME) $(OBJ) 

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	@make -C $(LIBRARIES_PATH) clean
	@RM -f $(OBJ) 
	
fclean : clean
	rm -f $(NAME)
	@make fclean -C $(LIBRARIES_PATH)

re : fclean all

.PHONY: all clean fclean re
