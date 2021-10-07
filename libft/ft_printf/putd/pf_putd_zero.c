/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putd_zero.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:19:53 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/01 15:17:10 by dvan-kri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"

static void	pf_putd_zero_width(t_convert *p)
{
	int	i;

	i = 0;
	if (p->d < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
		p->d = -(p->d);
	}
	while (p->width > i + ft_intcountchars(p->d))
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	ft_putnbr_fd((p->d), 1);
	i += ft_intcountchars(p->d);
	p->count += i;
}

void	pf_putd_zero(t_convert *p)
{
	if (p->width > ft_intcountchars(p->d))
	{
		pf_putd_zero_width(p);
	}
	else
	{
		ft_putnbr_fd((p->d), 1);
		p->count += ft_intcountchars(p->d);
	}
}
