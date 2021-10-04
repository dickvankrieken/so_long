NAME = so_long

SRCS = srcs/so_long.c srcs/hooks.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

test: $(NAME)
	./$(NAME)

all: $(NAME)

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
