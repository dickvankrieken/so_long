#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dvan-kri <dvan-kri@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/27 22:20:58 by dvan-kri      #+#    #+#                  #
#    Updated: 2021/08/15 15:12:19 by dvan-kri      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME =			libft.a

#---------------------- DIRECTORIES ------------------#
HDR_DIR =		includes/
OBJ_DIR =		obj/
PRINTF_DIR =	ft_printf/
GNL_DIR =		ft_gnl/

#---------------------- SOURCES ----------------------#
PRINTF_SRCS =	ft_printf.c \
				pf_checkfunctions.c \
				pf_checkfunctions_precision.c \
				pf_ultohex.c \
				pf_putfunctions.c \
				pf_putc.c \
				puts/pf_puts.c \
				puts/pf_puts_width.c \
				putd/pf_putd.c \
				putd/pf_putd_minus.c \
				putd/pf_putd_zero.c \
				pf_putp.c \
				putu/pf_putu.c \
				putu/pf_putu_minus.c \
				putu/pf_putu_zero.c \
				putx/pf_putx.c \
				putx/pf_putx_precision.c \
				putx/pf_putx_minus.c \

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

#---------------------- FILES ------------------------#
PRINTF_FILES =	$(addprefix $(PRINTF_DIR), $(PRINTF_SRCS))

#---------------------- OBJECTS ----------------------#
PRINTF_OBJS =		$(PRINTF_FILES:.c=.o)
LIBFT_OBJS =		$(LIBFT_SRCS:.c=.o) $(LIBFT_BONUS_SRCS:.c=.o)

#---------------------- FLAGS ------------------------#
C_FLAGS =	-Werror -Wextra -Wall

#---------------------- RULES ------------------------#
all: $(NAME)

$(NAME): $(PRINTF_OBJS) $(LIBFT_OBJS)
	ar rcs $@ $(PRINTF_OBJS) $(LIBFT_OBJS)
	ranlib $@

$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c
	$(CC) -c $(C_FLAGS) -o $@ $<

%.o: %.c
	$(CC) -c $(C_FLAGS) -o $@ $<

clean:
	rm -rf $(PRINTF_OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
