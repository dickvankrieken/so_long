/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_checkfunctions_precision.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/02 10:19:48 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/01 15:12:11 by dvan-kri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void	pf_getprecisionandfree(char *format, int i, int j, t_convert *p)
{
	char	*string;

	string = ft_substr(format, i, j);
	p->precision = ft_atoi(string);
	free(string);
}

int	pf_checkprecision(char *format, t_convert *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (format[0] == '.')
	{
		i++;
		if (format[i] == '*')
		{
			p->precision = va_arg(p->ap, int);
			i++;
		}
		else
		{
			while (ft_isdigit(format[i + j]))
				j++;
			if (j)
				pf_getprecisionandfree(format, i, j, p);
			else
				p->precision = 0;
		}
	}
	return (i);
}
