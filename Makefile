# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dvan-kri <dvan-kri@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/20 12:21:21 by dvan-kri      #+#    #+#                  #
#    Updated: 2021/10/29 13:15:19 by dvan-kri      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = srcs/so_long.c srcs/hooks.c srcs/parse.c srcs/map.c srcs/map_check.c srcs/map_check2.c srcs/game.c srcs/move.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $(CFLAGS) -o $@ $^

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) -Imlx $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
