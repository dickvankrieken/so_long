#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/so_long.h"
#include "../includes/keycodes.h"
#include "../libft/includes/ft_printf.h"

void	ft_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char	*dst;
	int		offset;

	offset = y * img->line + x * (img->bpp / 8);
	dst = img->addr + offset;
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

void	draw_player(t_game *d)
{
	d->img.img = mlx_new_image(d->window.mlx, 400, 400);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp, &d->img.line, &d->img.endian);
	d->img.img = mlx_xpm_file_to_image(d->window.mlx, "./assets/player.xpm", &d->img.width, &d->img.height);
	mlx_put_image_to_window(d->window.mlx, d->window.win, d->img.img, 0, 0);
	mlx_put_image_to_window(d->window.mlx, d->window.win, d->img.img, 64, 0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game_init(&game);
//	game.window.mlx = mlx_init();

	parse(&game, argv[1]);
	game.window.win = mlx_new_window(game.window.mlx, game.map.columns * 64, game.map.rows * 64, "so long");
	draw_map(&game);
//	draw_player(&game);
ft_printf("rows = %d", game.map.rows);
	mlx_loop_hook(game.window.mlx, game_loop, &game);
	mlx_hook(game.window.win, 17, (1L << 17), close_window, &game.window);
	mlx_hook(game.window.win, 02, (1L << 0), hook_key_press, &game.window);

	mlx_loop(game.window.mlx);
}
