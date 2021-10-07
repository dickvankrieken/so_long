/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putfunctions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:19:23 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/01 15:14:47 by dvan-kri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

void	pf_putconversion(t_convert *p)
{
	if (p->type == 'c')
		pf_putc(p);
	if (p->type == 's')
		pf_puts(p);
	if (p->type == 'p')
		pf_putp(p);
	if (p->type == 'd' || p->type == 'i')
		pf_putd(p);
	if (p->type == 'u')
		pf_putu(p);
	if (p->type == 'x')
		pf_putx(p);
	if (p->type == 'X')
		pf_putx(p);
	if (p->type == '%')
		pf_putc(p);
}

void	pf_putspaces(t_convert *p, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(' ', 1);
		i++;
		p->count++;
	}
}

void	pf_putzero(t_convert *p, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd('0', 1);
		i++;
		p->count++;
	}
}
