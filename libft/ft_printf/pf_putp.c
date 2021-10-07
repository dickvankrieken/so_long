/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putp.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:19:31 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/01 15:14:59 by dvan-kri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static int	pf_countp(t_convert *p)
{
	if (p->precision == 0 && p->p == 0)
		return (2);
	if (!p->p)
		return (3);
	return (2 + (int)ft_strlen(p->s));
}

static void	pf_printp(t_convert *p)
{
	ft_putstr_fd("0x", 1);
	p->count += 2;
	if (p->precision == 0 && p->p == 0)
		return ;
	ft_putstr_fd(p->s, 1);
	p->count += (int)ft_strlen(p->s);
}

void	pf_putp(t_convert *p)
{
	int		len;

	len = 0;
	p->s = pf_ultohex(p->p, 0);
	if (p->minus)
	{
		pf_printp(p);
		pf_putspaces(p, p->width - pf_countp(p));
		free(p->s);
		return ;
	}
	len = pf_countp(p);
	while (p->width > len)
	{
		ft_putchar_fd(' ', 1);
		len++;
		p->count++;
	}
	pf_printp(p);
	free(p->s);
}
