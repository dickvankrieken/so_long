/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_puts.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:20:01 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/01 15:15:24 by dvan-kri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"

static void	pf_puts_checkprecision(t_convert *p)
{
	if (p->precision > -1)
	{
		if (p->precision < (int)ft_strlen(p->s))
		{
			write(1, p->s, p->precision);
			p->count += p->precision;
		}
		else
		{
			write(1, p->s, ft_strlen(p->s));
			p->count += ft_strlen(p->s);
		}
	}
	else
	{
		write(1, p->s, ft_strlen(p->s));
		p->count += (int)ft_strlen(p->s);
	}
}

static void	pf_puts_minus(t_convert *p)
{
	if (p->width)
	{
		if (p->precision > -1 && p->precision < (int)ft_strlen(p->s))
		{
			write(1, p->s, p->precision);
			p->count += p->precision;
			pf_putspaces(p, p->width - p->precision);
		}
		else
		{
			write(1, p->s, ft_strlen(p->s));
			p->count += ft_strlen(p->s);
			pf_putspaces(p, p->width - ft_strlen(p->s));
		}
	}
	else if (p->precision > -1 && p->precision < (int)ft_strlen(p->s))
		p->count += write(1, p->s, p->precision);
	else
		p->count += write(1, p->s, ft_strlen(p->s));
}

void	pf_puts(t_convert *p)
{
	if (p->s)
	{
		if (p->minus)
		{
			pf_puts_minus(p);
		}
		else if (p->width)
		{
			pf_puts_width(p);
		}
		else
		{
			pf_puts_checkprecision(p);
		}
	}
}
