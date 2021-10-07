/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putuint_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/02 10:35:09 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/13 10:45:40 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	convert_uint(unsigned int n, int fd)
{
	if (n >= 10)
		convert_uint(n / 10, fd);
	ft_putchar_fd((char)(n % 10 + '0'), fd);
	return ;
}

void	ft_putuint_fd(unsigned int n, int fd)
{
	convert_uint(n, fd);
	return ;
}
