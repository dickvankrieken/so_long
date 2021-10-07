/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putu.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:20:13 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/01 15:17:26 by dvan-kri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"

void	pf_putu(t_convert *p)
{
	if (p->minus)
		pf_putu_minus(p);
	else if (p->zero)
		pf_putu_zero(p);
	else if (p->precision == 0 && p->u == 0 && p->width)
		pf_putu_width_checkprecision(p);
	else if (p->width > ft_uintcountchars(p->u))
		pf_putu_width_checkprecision(p);
	else if (p->precision > ft_uintcountchars(p->u))
		pf_putu_precision(p);
	else
	{
		if (!(p->precision == 0 && p->u == 0))
		{
			ft_putuint_fd((p->u), 1);
			p->count += ft_uintcountchars(p->u);
		}
	}
}

void	pf_putu_width(t_convert *p)
{
	int	i;

	i = 0;
	if (p->precision == 0 && p->u == 0)
	{
		while (i < p->width)
		{
			ft_putchar_fd(' ', 1);
			i++;
			p->count++;
		}
	}
	else
	{
		while (i < p->width - ft_uintcountchars(p->u))
		{
			ft_putchar_fd(' ', 1);
			i++;
			p->count++;
		}
		ft_putuint_fd((p->u), 1);
		p->count += ft_uintcountchars(p->u);
	}
}

void	pf_putu_width_checkprecision(t_convert *p)
{
	if (p->precision > ft_uintcountchars(p->u))
		pf_putu_width_precision(p);
	else
		pf_putu_width(p);
}

int	pf_putu_precision(t_convert *p)
{
	int	i;
	int	len;

	len = ft_uintcountchars(p->u);
	i = 0;
	while (p->precision > len)
	{
		ft_putchar_fd('0', 1);
		len++;
		i++;
	}
	if (!(p->u == 0 && p->precision == 0))
	{
		ft_putuint_fd((p->u), 1);
		i += ft_uintcountchars(p->u);
	}
	p->count += i;
	return (i);
}

void	pf_putu_width_precision(t_convert *p)
{
	int	i;

	i = 0;
	if (p->width > p->precision)
	{
		if (p->precision > ft_uintcountchars(p->u))
		{
			while (i < p->width - p->precision)
			{
				ft_putchar_fd(' ', 1);
				i++;
			}
		}
		else
		{
			while (i < p->width - ft_uintcountchars(p->u))
			{
				ft_putchar_fd(' ', 1);
				i++;
			}
		}
	}
	pf_putu_precision(p);
	p->count += i;
}
