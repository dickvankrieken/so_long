/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 21:06:29 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/20 17:44:56 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_convert
{
	va_list			ap;
	int				count;
	int				width;
	int				precision;
	int				minus;
	int				zero;
	char			type;
	char			c;
	char			*s;
	unsigned long	p;
	int				d;
	int				i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	uc_x;
	int				x_int;
}	t_convert;

int		pf_checkprecision(char *format, t_convert *p);

int		ft_printf(const char *format, ...);
void	pf_argtostruct(t_convert *p);

int		pf_check_conversion(char *format, t_convert *p);
void	pf_getprecisionandfree(char *format, int i, int j, t_convert *p);

char	*pf_ultohex(unsigned long n, int isupper);

void	pf_putconversion(t_convert *p);
void	pf_putspaces(t_convert *p, int len);
void	pf_putzero(t_convert *p, int len);
void	pf_putc(t_convert *p);

void	pf_puts(t_convert *p);
void	pf_puts_width(t_convert *p);
void	pf_puts_width_precision(t_convert *p);
void	pf_puts_width_zero(t_convert *p);

void	pf_putd(t_convert *p);
void	pf_putd_precision(t_convert *p);
void	pf_putd_width_precision(t_convert *p);

void	pf_putd_zero(t_convert *p);

void	pf_putd_minus(t_convert *p);

void	pf_putp(t_convert *p);

void	pf_putx(t_convert *p);
void	pf_putx_precision(t_convert *p);
void	pf_putx_checkprecision(t_convert *p);
void	pf_putx_minus(t_convert *p);

void	pf_putu(t_convert *p);
char	*ft_uitoa(unsigned int n);
int		pf_putu_precision(t_convert *p);
void	pf_putu_width(t_convert *p);
void	pf_putu_width_checkprecision(t_convert *p);
void	pf_putu_width_precision(t_convert *p);
void	pf_putu_minus(t_convert *p);
void	pf_putu_zero(t_convert *p);
void	pf_putu_zero_width(t_convert *p);

#endif
