# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 18:22:16 by mstefano          #+#    #+#              #
#    Updated: 2024/04/10 17:47:43 by mstefano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN=\033[0;32m
RESET=\033[0m
RED=\033[0;31m
CHECK=\xE2\x9C\x94
BROOM=\xF0\x9F\xA7\xB9
NAME = push_swap
BONUS_NAME = checker
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

BONUS_SRC = checker.c \
			operations.c \
			operations1.c \
			operations2.c \
			creatingstack.c \
			utils.c \
			utils1.c \
			libraries/get_next_line/get_next_line_bonus.c \
			libraries/get_next_line/get_next_line_utils_bonus.c \
		
OBJ = $(SRC:.c=.o) 
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: $(LIBRARIES) $(BONUS_NAME)

$(LIBRARIES):
	@make -C $(LIBRARIES_PATH)
	@echo "$(GREEN)$(CHECK)Compiled Libraries Successfully$(CHECK)$(RESET)"

$(NAME): $(LIBRARIES) $(OBJ)  
	@cc $(CFLAGS) $(LIBRARIES) -o $(NAME) $(OBJ)
	@echo "$(GREEN)$(CHECK)Compiled push_swap Successfully$(CHECK)$(RESET)"

$(BONUS_NAME): $(BONUS_OBJ)  
	@cc $(CFLAGS) $(LIBRARIES) -o $(BONUS_NAME) $(BONUS_OBJ)
	@echo "$(GREEN)$(CHECK)Compiled checker Successfully$(CHECK)$(RESET)"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	@make -C $(LIBRARIES_PATH) clean
	@$(RM) $(OBJ) $(BONUS_OBJ)
	
fclean : clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@make fclean -C $(LIBRARIES_PATH)
	@echo "$(RED)$(BROOM)Cleaned Successfully$(RESET)$(BROOM)"

re : fclean all bonus

.PHONY: all clean fclean re
