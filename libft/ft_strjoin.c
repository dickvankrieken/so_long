/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 15:57:47 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/13 10:45:40 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		dstsize;

	if (!s1 || !s2)
		return (NULL);
	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, dstsize);
	ft_strlcat(p, s2, dstsize);
	return (p);
}
