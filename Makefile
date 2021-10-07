NAME = fdf

SRCS = srcs/fdf.c srcs/hooks.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

all: $(NAME)
	./$(NAME) maps/42.fdf

$(NAME): $(OBJS) $(LIBFT)
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
