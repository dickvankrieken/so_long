/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:19:42 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/01 15:16:56 by dvan-kri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"

static void	pf_putd_width_precision_putspaces(t_convert *p)
{
	int	i;

	i = 0;
	if (p->d < 0)
		i++;
	if (p->precision > ft_intcountnumbers(p->d))
	{
		while (i < p->width - p->precision)
		{
			ft_putchar_fd(' ', 1);
			i++;
			p->count++;
		}
	}
	else
	{
		while (i < p->width - ft_intcountchars(p->d))
		{
			ft_putchar_fd(' ', 1);
			i++;
			p->count++;
		}
	}
}

void	pf_putd_width_precision(t_convert *p)
{
	if (p->width > p->precision)
		pf_putd_width_precision_putspaces(p);
	pf_putd_precision(p);
}

void	pf_putd_precision(t_convert *p)
{
	int	count;

	if (p->precision == 0 && p->d == 0)
		return ;
	count = ft_intcountnumbers(p->d);
	if (p->precision > count)
	{
		if (p->d < 0)
		{
			ft_putchar_fd('-', 1);
			p->d = -(p->d);
			p->count++;
		}
		while (p->precision > count)
		{
			ft_putchar_fd('0', 1);
			count++;
			p->count++;
		}
	}
	ft_putnbr_fd((p->d), 1);
	p->count += ft_intcountchars(p->d);
}

void	pf_putd_width(t_convert *p)
{
	int	i;

	if (p->precision > ft_intcountnumbers(p->d))
		pf_putd_width_precision(p);
	else
	{
		i = 0;
		while (i < p->width - ft_intcountchars(p->d))
		{
			ft_putchar_fd(' ', 1);
			i++;
			p->count++;
		}
		if (p->precision == 0 && p->d == 0)
		{
			ft_putchar_fd(' ', 1);
			p->count++;
		}
		else
		{
			ft_putnbr_fd((p->d), 1);
			p->count += ft_intcountchars(p->d);
		}
	}
}

void	pf_putd(t_convert *p)
{
	if (p->minus)
		pf_putd_minus(p);
	else if (p->zero && !(p->precision > -1))
		pf_putd_zero(p);
	else if (p->d == 0 && p->precision == 0 && p->width == 1)
		pf_putd_width(p);
	else if (p->width > ft_intcountchars(p->d))
		pf_putd_width(p);
	else if (p->precision > -1)
		pf_putd_precision(p);
	else
	{
		ft_putnbr_fd((p->d), 1);
		p->count += ft_intcountchars(p->d);
	}
}
