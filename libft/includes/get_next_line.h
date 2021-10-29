/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/19 10:31:09 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/29 13:32:51 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <stdlib.h>

char				*find_nl(char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				gnl_strlcat(char *dst, const char *src, size_t dstsize);
char				*gnl_strjoin(char const *s1, char const *s2);
char				*gnl_strdup(const char *s1);
size_t				gnl_strlen(const char *s);

int					get_next_line(int fd, char **c);

#endif
