#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "../so_long.h"
#include "../libft/includes/ft_printf.h"

void	ft_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char	*dst;
	int		offset;

	offset = y * img->line + x * (img->bpp / 8);
	dst = img->addr + offset;
	*(unsigned int *)dst = colour;
}

int	ft_pixel_get(t_img *img, int x, int y)
{
	char	*addr;

	addr = img->addr + (y * img->line) + x * (img->bpp / 8);
	return (*(unsigned int *)addr);
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


void	draw_redsquare(t_game *d)
{
	int	x;
	int y;
	int width;
	int height;

	d->img.img = mlx_new_image(d->window.mlx, 640, 480);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp, &d->img.line, &d->img.endian);
	y = 0;
	x = 0;
	while (y < 320)
	{
		while (x < 320)
		{
			ft_pixel_put(d->img.img, x, y, 0x00FF0000);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(d->window.mlx, d->window.win, d->img.img, 0, 0);
}

void	draw_player(t_game *d)
{
	int width;
	int height;
	int	x;
	int	y;
	int c;

	d->img.img = mlx_new_image(d->window.mlx, 400, 400);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp, &d->img.line, &d->img.endian);
	d->img.img = mlx_xpm_file_to_image(d->window.mlx, "./assets/player.xpm", &width, &height);
	while (y < height)
	{
		while (x < width)
		{
			c = ft_pixel_get(&d->img, x, y);
			ft_pixel_put(&d->img, x, y, c);
			x++;
		}
		x = 200;
		y++;
	}
	mlx_put_image_to_window(d->window.mlx, d->window.win, d->img.img, 600, 200);
}

int	print_mouse_enter(int z, int x, int y, t_game *game)
{
	int c;

	c = ft_pixel_get(&game->img, x, y);
	ft_printf("colour = 0x00%X, x = %d, y = %d\n", c, x, y);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.window.mlx = mlx_init();
	game.window.win = mlx_new_window(game.window.mlx, 640, 480, "so long");
	parse(&game, argv[1]);
	draw_player(&game);
	mlx_key_hook(game.window.win, ft_mlx_key_pressed, &game.window);
	mlx_hook(game.window.win, 17, (1L << 17), close_window, &game.window);
	mlx_hook(game.window.win, 04, (1L << 2), print_mouse_enter, &game.window);
	mlx_loop(game.window.mlx);
}
