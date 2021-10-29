/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 12:37:58 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/29 11:44:46 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

void	player_move(t_game *game, int y, int x)
{
	if (check_empty_tile(game, y, x))
		return ;
	else if (check_collectible_tile(game, y, x))
		return ;
	if (check_exit_tile(game, y, x))
		return ;
}

int	check_collectible_tile(t_game *game, int move_y, int move_x)
{
	if (game->map.data[game->player.y + move_y][game->player.x + move_x] == 'C')
	{
		game->map.data[game->player.y + move_y][game->player.x + move_x] = 'P';
		game->map.data[game->player.y][game->player.x] = '0';
		game->map.collectibles--;
		game->player.moves++;
		ft_printf("Move %d\n", game->player.moves);
		draw_map(game);
		return (1);
	}
	return (0);
}

int	check_empty_tile(t_game *game, int move_y, int move_x)
{
	if (game->map.data[game->player.y + move_y][game->player.x + move_x] == '0')
	{
		game->map.data[game->player.y + move_y][game->player.x + move_x] = 'P';
		game->map.data[game->player.y][game->player.x] = '0';
		game->player.moves++;
		ft_printf("Move %d\n", game->player.moves);
		draw_map(game);
		return (1);
	}
	return (0);
}

int	check_exit_tile(t_game *game, int move_y, int move_x)
{
	if (game->map.data[game->player.y + move_y][game->player.x + move_x] == 'E'
			&& game->map.collectibles == 0)
	{
		game->map.data[game->player.y + move_y][game->player.x + move_x] = 'P';
		game->map.data[game->player.y][game->player.x] = '0';
		game->player.moves++;
		ft_printf("Move %d\n", game->player.moves);
		draw_map(game);
		free_map_data(&game->map, game->map.rows);
		exit(EXIT_SUCCESS);
		return (1);
	}
	return (0);
}
