NAME = RTV1

DEPS = *.h
DEPSDIR = includes
SRC = main.c
SRCDIR = srcs
OBJ = $(SRC:.c=.o)
CC = /usr/bin/gcc
CCFLAGS = -Wall -Wextra -Werror -O3
RM = /bin/rm
RMFLAGS = -f
LIB = ft
LIBDIR = $(SRCDIR)/libft

all: $(NAME)
$(NAME): $(OBJ)
	make -C $(LIBDIR)
	$(CC) $(CCFLAGS)  $(DEBUG) srcs/libft/libft.a minilibx_macos/libmlx.a  -o $(NAME) $^ -framework OpenGL -framework AppKit

$(OBJ): %.o : $(SRCDIR)/%.c $(DEPSDIR)/$(DEPS)
	$(CC) $(CCFLAGS) -I $(DEPSDIR) -I $(LIBDIR) $(DEBUG) -c -o $@ $<

$(SRCDIR)/$(SRC):

$(DEPSDIR)/$(DEPS):

clean:
	make -C $(LIBDIR) clean
	$(RM) $(RMFLAGS) $(OBJ)

fclean: clean
	make -C $(LIBDIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re