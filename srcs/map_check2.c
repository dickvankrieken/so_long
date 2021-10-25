/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 15:26:03 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/25 16:31:08 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"

void	multiple_to_one_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.rows)
	{
		while (j < game->map.columns)
		{
			if (game->map.data[i][j] == 'P')
			{
				game->map.data[i][j] = '0';
				game->map.player--;
				if (game->map.player == 1)
					return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	count_rows_free_empty_lines(t_map *map)
{
	int	i;
	int	j;

	i = 0;	
	while (i < map->rows && ft_strlen(map->data[i]))
	{
		i++;
	}
	j = i;
	while (i < map->rows)
	{
		free(map->data[i]);
		i++;
	}
	map->rows = j;
}



void	validate_map(t_game *game)
{
	int	i;

	i = 0;
	count_rows_free_empty_lines(&game->map);
	line_is_walls(game->map, game->map.data[0]);
	game->map.columns = ft_strlen(game->map.data[0]);
	while (i < game->map.rows - 1)
	{
		check_tiles(game, game->map.data[i]);
		if (game->map.columns != ft_strlen(game->map.data[i]))
		{
			free_map_data(&game->map, game->map.rows);
			ft_printf("Error\nMap must be rectangular");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	check_requirements(game->map);
	line_is_walls(game->map, game->map.data[i]);
}
