NAME = fdf

SRCS = srcs/fdf.c srcs/hooks.c srcs/parse.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

GNL = libft/gnl/get_next_line.c libft/gnl/get_next_line_utils.c

all: $(NAME)
	./$(NAME) maps/42.fdf

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(CC) -g -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit $(CFLAGS) -o $@ $^

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) -g -fsanitize=address -Imlx -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
