/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 19:04:00 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/13 10:45:40 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}
