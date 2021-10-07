/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:19:09 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/01 15:13:21 by dvan-kri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static void	pf_putc_width(t_convert *p)
{
	if (p->minus)
	{
		ft_putchar_fd(p->c, 1);
		pf_putspaces(p, p->width - 1);
	}
	else if (p->zero)
	{
		pf_putzero(p, p->width - 1);
		ft_putchar_fd(p->c, 1);
	}
	else
	{
		pf_putspaces(p, p->width - 1);
		ft_putchar_fd(p->c, 1);
	}
	p->count += 1;
}

void	pf_putc(t_convert *p)
{
	if (p->width)
	{
		pf_putc_width(p);
	}
	else
	{
		ft_putchar_fd(p->c, 1);
		p->count++;
	}
}
