# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 20:41:14 by aomega            #+#    #+#              #
#    Updated: 2020/11/12 07:28:45 by jabilbo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
NAME = RTv1
UNAME := $(shell uname -s)
	ifeq ($(UNAME),Linux)
		MLX_DIR = ./minilibx_linux/
		LIBS = -lmlx -lft -L$(LFT_DIR) -L$(MLX_DIR) -lm -lXext -lX11
		KEY = keys_linux.c
	endif
	ifeq ($(UNAME),Darwin)
		MLX_DIR = ./minilibx_macos/
		LIBS = -lmlx -lm -lft -L$(LFT_DIR) -L$(MLX_DIR) -framework OpenGL -framework AppKit
		KEY = keys_mac.c
	endif
HEADER = rt.h
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror -O3
SOURCES  = main.c draw.c sphere.c cylinder.c cone.c plane.c parse.c parse_ex.c parse_input.c \
camera_rotation.c intersects.c vector_math.c vector_math_dop.c ex.c  $(KEY)
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = -I$(HEADER_DIR) -I$(MLX_DIR) -I$(LFT_DIR)
MLX = $(MLX_DIR)libmlx.a
LFT_DIR = ./lft/
LFT = $(LFT_DIR)libft.a
HEADER_DIR = .

all: $(NAME)

$(NAME): $(MLX) $(LFT) $(OBJECTS)
	$(COMPILER) $(FLAGS) $(OBJECTS) $(INCLUDES) $(LIBS) -o $(NAME)

%.o: %.c $(HEADER)
	$(COMPILER) $(FLAGS) -o $@ -c $(INCLUDES) $<

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LFT):
	$(MAKE) -C $(LFT_DIR)

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX)
	rm -f $(LFT)

re: fclean all
