#include <stdlib.h>
#include <mlx.h>
#include "../so_long.h"

int	ft_mlx_key_pressed(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->window.mlx, game->window.win);
		exit(0);
	}
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->window.mlx, game->window.win);
	exit(0);
}
