# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 18:22:16 by mstefano          #+#    #+#              #
#    Updated: 2024/03/30 17:03:56 by mstefano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN=\033[0;32m
RESET=\033[0m
RED=\033[0;31m
CHECK=\xE2\x9C\x94
BROOM=\xF0\x9F\xA7\xB9
NAME = push_swap
RM = rm -f
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
		utils.c \
		allsorts.c \
		sorting_utils.c \
		sorting_utils1.c \
		ksort.c \
		utils1.c \
		
OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(LIBRARIES):
	@make -C $(LIBRARIES_PATH)
	@echo "$(GREEN)$(CHECK)Compiled Libraries Successfully$(CHECK)$(RESET)"

$(NAME): $(LIBRARIES) $(OBJ)  
	@cc $(CFLAGS) $(LIBRARIES) -o $(NAME) $(OBJ)
	@echo "$(GREEN)$(CHECK)Compiled push_swap Successfully$(CHECK)$(RESET)"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	@make -C $(LIBRARIES_PATH) clean
	@$(RM) $(OBJ)
	
fclean : clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBRARIES_PATH)
	@echo "$(RED)$(BROOM)Cleaned Successfully$(RESET)$(BROOM)"

re : fclean all

.PHONY: all clean fclean re
