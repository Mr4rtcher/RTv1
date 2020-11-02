# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 22:47:45 by jabilbo           #+#    #+#              #
#    Updated: 2020/10/22 15:19:21 by jabilbo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isdigit.c ft_memcpy.c ft_putendl_fd.c ft_strclr.c ft_striteri.c\
	  ft_strncat.c ft_strsplit.c ft_isprint.c ft_memdel.c ft_putnbr.c\
	  ft_strcmp.c ft_strjoin.c ft_strncmp.c ft_strstr.c ft_atoi.c\
	  ft_itoa.c ft_memmove.c ft_putnbr_fd.c ft_strcpy.c ft_strlcat.c\
	  ft_strncpy.c ft_strsub.c ft_bzero.c ft_memalloc.c ft_memset.c\
	  ft_putstr.c ft_strdel.c ft_strlcpy.c ft_strnequ.c ft_strtrim.c\
	  ft_isalnum.c ft_memccpy.c ft_putchar.c ft_putstr_fd.c ft_strdup.c\
	  ft_strlen.c ft_strnew.c ft_tolower.c ft_isalpha.c ft_memchr.c\
	  ft_putchar_fd.c ft_strcat.c ft_strequ.c ft_strmap.c ft_strnstr.c\
	  ft_toupper.c ft_isascii.c ft_memcmp.c ft_putendl.c ft_strchr.c\
	  ft_striter.c ft_strmapi.c ft_strrchr.c

OBJ = $(SRC:%.c=%.o)

INC = libft.h

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I $(INC) -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
