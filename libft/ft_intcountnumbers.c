/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intcountnumbers.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 14:01:51 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/06/10 14:12:36 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_intcountnumbers(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
