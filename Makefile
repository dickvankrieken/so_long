# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dvan-kri <dvan-kri@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/20 12:21:21 by dvan-kri      #+#    #+#                  #
#    Updated: 2021/10/25 13:36:31 by dvan-kri      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = srcs/so_long.c srcs/hooks.c srcs/parse.c srcs/map.c srcs/map_check.c srcs/map_check2.c srcs/game.c srcs/move.c srcs/move_checks.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

GNL = libft/gnl/get_next_line.c libft/gnl/get_next_line_utils.c

all: $(NAME)
	./$(NAME) map1.ber

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $(CFLAGS) -o $@ $^

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) -Imlx -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
