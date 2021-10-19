#include <stdlib.h>
#include <mlx.h>
#include "../includes/so_long.h"
#include "../includes/keycodes.h"
#include "../libft/includes/ft_printf.h"

int	hook_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		free_map_data(&game->map, game->map.rows);
		mlx_destroy_window(game->window.mlx, game->window.win);
		exit(0);
	}
	if (keycode == KEY_W)
	{
		player_move_up(game);
	}
	if (keycode == KEY_A)
	{
		player_move_left(game);
	}
	if (keycode == KEY_S)
	{
		player_move_down(game);
	}
	if (keycode == KEY_D)
	{
		player_move_right(game);
	}			
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->window.mlx, game->window.win);
	exit(0);
}
