/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putx_minus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:20:33 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/20 11:32:40 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"

static void	pf_putx_minus_width_precision(t_convert *p)
{
	int	i;

	i = p->count;
	pf_putx_precision(p);
	i = p->count - i;
	while (i < p->width)
	{
		ft_putchar_fd(' ', 1);
		i++;
		p->count++;
	}
}

static void	pf_putx_minus_width(t_convert *p)
{
	int	i;
	int	len;

	len = 0;
	if (!(p->x_int == 0 && p->precision == 0))
	{
		len = ft_strlen(p->s);
		write(1, p->s, len);
		p->count += len;
	}
	i = 0;
	while (i < p->width - len)
	{
		ft_putchar_fd(' ', 1);
		i++;
		p->count++;
	}
}

void	pf_putx_minus(t_convert *p)
{
	if (p->width)
	{
		if (p->precision)
		{
			pf_putx_minus_width_precision(p);
		}
		else
		{
			pf_putx_minus_width(p);
		}
	}
	else if (p->precision > (int)ft_strlen(p->s))
	{
		pf_putx_precision(p);
	}
	else
	{
		write(1, p->s, ft_strlen(p->s));
		p->count += ft_strlen(p->s);
	}
}
