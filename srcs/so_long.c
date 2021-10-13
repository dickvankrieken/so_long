#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "../so_long.h"
#include "../libft/includes/ft_printf.h"

void	my_pixel_put(t_game *game, int x, int y, unsigned int colour)
{
	char	*dst;
	int		offset;

	offset = y * game->img.line + x * (game->img.bpp / 8);
	dst = game->img.address + offset;
	*(unsigned int *)dst = colour;
}

void	check_map_argument(int argc)
{
	if (argc < 2)
	{
		ft_printf("No map provided!");
		exit(0);
	}
	if (argc > 2)
	{
		ft_printf("Too many arguments!");
		exit(0);
	}
}

void	init(t_game *game)
{
	game->window.mlx = mlx_init();
	game->window.win = mlx_new_window(game->window.mlx, 640, 480, "so long");
}

void	draw_game_image(t_game *d)
{
	int			x;

	d->img.img = mlx_new_image(d->window.mlx, 640, 480);
	d->img.address = mlx_get_data_addr(d->img.img, &d->img.bpp, &d->img.line, &d->img.endian);
	x = 1;
	my_pixel_put(d, 640 / 2, x, 0x000FFFFFF);
	while (x < 480)
	{
		my_pixel_put(d, 640 / 2, x, 0x000FFFFFF);
		x++;
	}
	x = 1;
	while (x < 640)
	{
		my_pixel_put(d, x, 480 / 2, 0x000FFFFFF);
		x++;
	}
	mlx_put_image_to_window(d->window.mlx, d->window.win, d->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.window.mlx = mlx_init();
	game.window.win = mlx_new_window(game.window.mlx, 640, 480, "so long");
	parse(&game, argv[1]);
	draw_game_image(&game);
	mlx_key_hook(game.window.win, ft_mlx_key_pressed, &game.window);
	mlx_hook(game.window.win, 17, (1L << 17), close_window, &game.window);
	mlx_loop(game.window.mlx);
}
