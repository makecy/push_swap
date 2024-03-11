# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 18:22:16 by mstefano          #+#    #+#              #
#    Updated: 2024/03/11 16:57:10 by mstefano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3
LIBRARIES_PATH = ./libraries
LIBRARIES = $(LIBRARIES_PATH)/libraries.a


SRC = 	push_swap.c \
		operations.c \
		operations1.c \
		operations2.c \
		sorting.c \
		creatingstack.c \
		error_message.c \
		utils.c \
		

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(LIBRARIES):
	@make -C $(LIBRARIES_PATH)

$(NAME): $(LIBRARIES) $(OBJ)  
	@cc $(CFLAGS) $(LIBRARIES) -o $(NAME) $(OBJ)
	@echo "Compiled Successfully"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	@make -C $(LIBRARIES_PATH) clean
	@RM -f $(OBJ)
	
fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LIBRARIES_PATH)
	@echo "Cleaned Successfully"

re : fclean all

.PHONY: all clean fclean re
