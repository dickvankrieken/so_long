/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_checkfunctions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 19:08:34 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/20 18:23:37 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static int	pf_checktype(char *format, t_convert *p)
{
	if (*format == 'd' || *format == 'i' || *format == 'u'
		|| *format == 'x' || *format == 'X' || *format == 'c'
		|| *format == 'p' || *format == 's' || *format == '%')
	{
		p->type = *format;
		return (1);
	}
	return (0);
}

static int	pf_checkwidthdigit(char *format, t_convert *p)
{
	char	*string;
	int		i;

	i = 0;
	while (ft_isdigit(format[i]))
		i++;
	if (i)
	{
		string = ft_substr(format, 0, i);
		p->width = ft_atoi(string);
		free(string);
	}
	return (i);
}

static int	pf_checkasterisk(char *format, t_convert *p)
{
	if (*format == '*')
	{
		p->width = va_arg(p->ap, int);
		if (p->width < 0)
		{
			p->minus = 1;
			p->width *= -1;
		}
		return (1);
	}
	return (0);
}

static int	pf_checkflag(char *format, t_convert *p)
{
	int	i;

	i = 0;
	if (format[i] == '0')
	{
		p->zero = 1;
		i++;
	}
	else if (format[i] == '-')
	{
		p->minus = 1;
		i++;
		if (p->zero == 1)
			p->zero = 0;
	}
	return (i);
}

int	pf_check_conversion(char *format, t_convert *p)
{
	int	i;

	i = 0;
	while (pf_checkflag(&format[i], p))
		i++;
	if (pf_checkasterisk(&format[i], p))
		i++;
	if (pf_checkwidthdigit(&format[i], p))
		i += ft_intcountchars(p->width);
	if (format[i] == '.')
		i += pf_checkprecision(&format[i], p);
	while (!pf_checktype(&format[i], p))
		i++;
	if (pf_checktype(&format[i], p))
		i++;
	pf_argtostruct(p);
	return (i);
}
