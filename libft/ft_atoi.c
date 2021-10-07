/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 12:15:27 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/05/19 10:56:08 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(const char str)
{
	if (str == ' ' || str == '\t' || str == '\n'
		|| str == '\v' || str == '\f' || str == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	k;

	res = 0;
	i = 0;
	k = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		k = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + ((int)str[i] - 48);
		i++;
	}
	return (res * k);
}
