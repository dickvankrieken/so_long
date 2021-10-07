/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_ultohex.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:19:36 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/01 15:14:27 by dvan-kri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	numberofchars(unsigned long n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static char	*ft_convert(unsigned long num, int allchars, int isupper)
{
	int		i;
	char	*a;

	i = allchars - 1;
	a = ft_calloc(allchars + 1, sizeof(char));
	if (!a)
		return (NULL);
	while (i >= 0)
	{
		if ((num % 16) <= 9)
			a[i] = (num % 16) + '0';
		else if (isupper)
			a[i] = (num % 16) + 55;
		else
			a[i] = (num % 16) + 87;
		num /= 16;
		i--;
	}
	return (a);
}

char	*pf_ultohex(unsigned long n, int isupper)
{
	int	allchars;

	if (n == 0)
		return (ft_strdup("0"));
	allchars = numberofchars(n);
	return (ft_convert(n, allchars, isupper));
}
