# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dvan-kri <dvan-kri@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/27 22:20:58 by dvan-kri      #+#    #+#                  #
#    Updated: 2021/10/29 12:47:19 by dvan-kri      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a

#---------------------- DIRECTORIES ------------------#
HDR_DIR =		includes/
OBJ_DIR =		obj/
PRINTF_DIR =	ft_printf/
GNL_DIR =		gnl/

#---------------------- SOURCES ----------------------#
PRINTF_SRCS =	ft_printf/ft_printf.c \
				ft_printf/pf_checkfunctions.c \
				ft_printf/pf_checkfunctions_precision.c \
				ft_printf/pf_ultohex.c \
				ft_printf/pf_putfunctions.c \
				ft_printf/pf_putc.c \
				ft_printf/puts/pf_puts.c \
				ft_printf/puts/pf_puts_width.c \
				ft_printf/putd/pf_putd.c \
				ft_printf/putd/pf_putd_minus.c \
				ft_printf/putd/pf_putd_zero.c \
				ft_printf/pf_putp.c \
				ft_printf/putu/pf_putu.c \
				ft_printf/putu/pf_putu_minus.c \
				ft_printf/putu/pf_putu_zero.c \
				ft_printf/putx/pf_putx.c \
				ft_printf/putx/pf_putx_precision.c \
				ft_printf/putx/pf_putx_minus.c \

LIBFT_SRCS = 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
				ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c \
				ft_strlcat.c ft_tolower.c ft_toupper.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_strchr.c ft_strncmp.c \
				ft_strrchr.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_intcountchars.c ft_putuint_fd.c \
				ft_uintcountchars.c ft_intcountnumbers.c
LIBFT_BONUS_SRCS = 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

GNL_SRCS =		get_next_line.c get_next_line_utils.c

#---------------------- OBJECTS ----------------------#
PRINTF_OBJS =		$(PRINTF_SRCS:.c=.o)
LIBFT_OBJS =		$(LIBFT_SRCS:.c=.o) $(LIBFT_BONUS_SRCS:.c=.o)
GNL_OBJS =			$(GNL_SRCS:.c=.o)

#---------------------- FLAGS ------------------------#
C_FLAGS =	-Werror -Wextra -Wall

#---------------------- RULES ------------------------#
all: $(NAME)

$(NAME): $(PRINTF_OBJS) $(LIBFT_OBJS) $(GNL_OBJS)
	ar rcs $@ $(PRINTF_OBJS) $(LIBFT_OBJS) $(GNL_OBJS)
	ranlib $@

%.o: %.c
	$(CC) -c $(C_FLAGS) -o $@ $<

clean:
	rm -rf $(PRINTF_OBJS) $(LIBFT_OBJS) $(GNL_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
