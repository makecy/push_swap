# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 13:14:15 by mstefano          #+#    #+#              #
#    Updated: 2023/11/01 15:29:04 by mstefano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -std=c99

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	  ft_atoi.c ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c\
	  ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c\
	  ft_toupper.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
	  ft_strlcat.c ft_strlcpy.c ft_strdup.c ft_calloc.c ft_putchar_fd.c\
	  ft_putstr_fd.c ft_putendl_fd.c ft_strmapi.c ft_putnbr_fd.c\
	  ft_striteri.c ft_substr.c ft_strjoin.c ft_strtrim.c\
	  ft_itoa.c ft_split.c\
	  
BONUSSRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		   ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\

BONUSOBJ = $(BONUSSRC:.c=.o)

OBJ = $(SRC:.c=.o)

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)

bonus : $(OBJ) $(BONUSOBJ)
	@ar rcs $(NAME) $(OBJ) $(BONUSOBJ) 

clean:
	@rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all 

.PHONY :clean fclean  all bonus
