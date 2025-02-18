NAME = push_swap
BONUS_NAME = checker
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g -I./inc

LIB = ./libraries/libraries.a

BINDIR = bin

SRCS = 	src/push_swap.c \
		src/operations.c \
		src/operations1.c \
		src/operations2.c \
		src/sorting.c \
		src/creatingstack.c \
		src/utils.c \
		src/allsorts.c \
		src/sorting_utils.c \
		src/sorting_utils1.c \
		src/ksort.c \
		src/utils1.c

BONUS_SRCS = src/checker.c \
			src/operations.c \
			src/operations1.c \
			src/operations2.c \
			src/creatingstack.c \
			src/utils.c \
			src/utils1.c \
			libraries/get_next_line/get_next_line_bonus.c \
			libraries/get_next_line/get_next_line_utils_bonus.c

OBJS = $(SRCS:%.c=$(BINDIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=$(BINDIR)/%.o)

all: $(NAME)

bonus: $(LIB) $(BONUS_NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)
	@echo $(GREEN)"Building $(NAME)"$(DEFAULT)

$(BONUS_NAME): $(LIB) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LIB)
	@echo $(GREEN)"Building $(BONUS_NAME)"$(DEFAULT)

$(BINDIR):
	@mkdir -p $(BINDIR)

$(BINDIR)/%.o: %.c | $(BINDIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	@if [ ! -d "libraries" ]; then \
		echo "Cloning libraries..."; \
		git clone https://github.com/makecy/libraries.git && \
		make -C libraries; \
	else \
		make -C libraries; \
	fi

clean:
	@rm -rf $(BINDIR)
	@make -C libraries clean
	@echo $(RED)"Cleaning $(NAME) object files"$(DEFAULT)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@rm -rf libraries
	@echo $(RED)"Cleaning $(NAME), $(BONUS_NAME) and libraries"$(DEFAULT)

re: fclean all bonus
	@echo $(GREEN)"Rebuilding everything"$(DEFAULT)

.PHONY: all bonus clean fclean re

DEFAULT = "\033[39m"
GREEN = "\033[32m"
RED = "\033[31m"