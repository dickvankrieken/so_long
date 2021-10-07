/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 11:36:41 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/13 10:45:40 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[j] && needle[i] && j < len)
	{
		while (haystack[j] != needle[i])
			j++;
		while (haystack[j] == needle[i] && j < len)
		{
			j++;
			i++;
			if (needle[i] == '\0')
				return ((char *)haystack + (j - i));
		}
		i = 0;
	}
	return (NULL);
}
