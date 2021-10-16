#include <stdlib.h>
#include <mlx.h>
#include "../includes/so_long.h"
#include "../includes/keycodes.h"

#include "../libft/includes/ft_printf.h"

int	hook_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->window.mlx, game->window.win);
		exit(0);
	}
	if (keycode == KEY_W)
	{
		if (game->img.img)
		{
			ft_printf("OK");
		}
	}
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->window.mlx, game->window.win);
	exit(0);
}
