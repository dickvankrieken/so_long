/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 15:56:56 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/13 10:45:40 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	convert_int(unsigned int n, int fd)
{
	if (n >= 10)
		convert_int(n / 10, fd);
	ft_putchar_fd((char)(n % 10 + '0'), fd);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int)n;
	convert_int(nbr, fd);
	return ;
}
