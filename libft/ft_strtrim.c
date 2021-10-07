/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 10:54:08 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/13 10:45:40 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_trimchar(char x, char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
	{
		if (x == c[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = 0;
	end = ft_strlen(s1);
	while (ft_trimchar(s1[start], (char *)set))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (ft_trimchar(s1[end - 1], (char *)set))
		end--;
	return (ft_substr((char *)s1, start, end - start));
}
