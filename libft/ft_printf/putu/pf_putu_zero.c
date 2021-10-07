/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putu_zero.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:20:23 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/01 15:17:42 by dvan-kri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"

void	pf_putu_zero(t_convert *p)
{
	if (p->width > ft_uintcountchars(p->u))
	{
		if (p->precision >= 0)
			pf_putu_width_precision(p);
		else
			pf_putu_zero_width(p);
	}
	else if (p->precision > ft_uintcountchars(p->u))
	{
		pf_putu_precision(p);
	}
	else if (!(p->precision == 0 && p->u == 0))
	{
		ft_putuint_fd((p->u), 1);
		p->count += ft_uintcountchars(p->u);
	}
}

void	pf_putu_zero_width(t_convert *p)
{
	int	i;

	i = 0;
	while (p->width > (i + ft_uintcountchars(p->u)))
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	ft_putuint_fd((p->u), 1);
	i += ft_uintcountchars(p->u);
	p->count += i;
}
