NAME = so_long

SRCS = srcs/so_long.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

practice:
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $(CFLAGS) -o $@ $^

test: $(NAME)
	./$(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
