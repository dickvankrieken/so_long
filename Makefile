NAME = so_long

SRCS = srcs/so_long.c \
	srcs/hooks.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

test: $(NAME)
	./$(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -g -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) -g -fsanitize=address -Imlx -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
