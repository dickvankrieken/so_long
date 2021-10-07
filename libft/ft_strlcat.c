/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 08:38:35 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/13 10:45:40 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

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
	max = dstsize - dstlen - 1;
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
