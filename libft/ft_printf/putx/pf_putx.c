/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putx.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:20:28 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/20 17:45:34 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"

static void	pf_putx_width_zero(t_convert *p)
{
	if (p->precision == 0 && (p->x == 0 || p->uc_x == 0))
	{
		pf_putspaces(p, p->width);
		return ;
	}
	else if (p->precision > -1 && p->precision > (int)ft_strlen(p->s))
	{
		pf_putspaces(p, p->width - p->precision);
		pf_putzero(p, p->precision - ft_strlen(p->s));
		write(1, p->s, ft_strlen(p->s));
	}
	else if (p->precision > -1)
	{
		pf_putspaces(p, p->width - ft_strlen(p->s));
		write(1, p->s, ft_strlen(p->s));
	}
	else
	{
		pf_putzero(p, p->width - ft_strlen(p->s));
		write(1, p->s, ft_strlen(p->s));
	}
	p->count += (int)ft_strlen(p->s);
}

static void	pf_putx_width(t_convert *p)
{
	if (p->zero)
		pf_putx_width_zero(p);
	else
	{
		if (p->precision > -1)
		{
			if (p->precision < (int)ft_strlen(p->s))
				pf_putspaces(p, p->width - (int)ft_strlen(p->s));
			else if (p->width > p->precision)
			{
				pf_putspaces(p, p->width - p->precision);
			}
			pf_putx_precision(p);
			return ;
		}
		else if (p->width > (int)ft_strlen(p->s))
		{
			pf_putspaces(p, p->width - ft_strlen(p->s));
		}
		write(1, p->s, ft_strlen(p->s));
		p->count += ft_strlen(p->s);
	}
}

void	pf_putx(t_convert *p)
{
	if (p->type == 'x')
	{
		p->x_int = p->x;
		p->s = pf_ultohex(p->x, 0);
	}
	else if (p->type == 'X')
	{
		p->x_int = p->uc_x;
		p->s = pf_ultohex(p->uc_x, 1);
	}
	if (p->precision == 0 && (p->x == 0 || p->uc_x == 0) && !(p->width))
	{
		free(p->s);
		return ;
	}
	if (p->s)
	{
		if (p->minus)
			pf_putx_minus(p);
		else if (p->width)
			pf_putx_width(p);
		else
			pf_putx_checkprecision(p);
	}
	free(p->s);
}
