/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/19 10:31:22 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/29 12:47:39 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

char	*find_nl(char *s)
{
	while (*s != '\0')
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	max;
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	if (dstsize > dstlen)
		max = dstsize - dstlen - 1;
	else
		max = 0;
	i = dstlen;
	j = 0;
	while (j < max && src[j])
	{
		*(dst + i) = *(src + j);
		i++;
		j++;
	}
	if (dstsize != 0)
		*(dst + i) = '\0';
	return (dstlen + srclen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		dstsize;
	int		s1len;
	int		i;

	if (s1 == NULL)
		s1len = 0;
	else
		s1len = ft_strlen(s1);
	dstsize = s1len + ft_strlen(s2) + 1;
	p = malloc((s1len + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i] && i + 1 < dstsize)
	{
		*(p + i) = *(s1 + i);
		i++;
	}
	*(p + i) = '\0';
	ft_strlcat(p, s2, dstsize);
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	ptr = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
