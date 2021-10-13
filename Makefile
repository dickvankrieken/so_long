NAME = so_long

SRCS = srcs/so_long.c srcs/hooks.c srcs/parse.c srcs/map.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

GNL = libft/gnl/get_next_line.c libft/gnl/get_next_line_utils.c

all: $(NAME)
	./$(NAME) map1.ber

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
