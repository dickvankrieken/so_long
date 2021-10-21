/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 15:26:03 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/21 15:26:24 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"

int	count_rows(t_map map)
{
	int	i;

	i = 0;
	while (ft_strlen(map.data[i]))
	{
		i++;
	}
	return (i);
}

void	validate_map(t_game *game)
{
	int	i;

	i = 0;
	game->map.rows = count_rows(game->map);
	line_is_walls(game->map.data[0]);
	game->map.columns = ft_strlen(game->map.data[0]);
	while (i < game->map.rows - 1)
	{
		check_tiles(game, game->map.data[i]);
		if (game->map.columns != ft_strlen(game->map.data[i]))
		{
			free_map_data(&game->map, i);
			ft_printf("Error\nMap must be rectangular");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	check_requirements(game->map);
	line_is_walls(game->map.data[i]);
}
