#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "../so_long.h"
#include "../libft/includes/ft_printf.h"

void	my_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char	*dst;
	int	offset;

	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
	*(unsigned int *)dst = colour;
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_img	image;
	int	x;

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
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 640, 480, "so_long");
	image.img_ptr = mlx_new_image(game.mlx, 640, 480);
	image.address = mlx_get_data_addr(image.img_ptr, &image.bits_per_pixel, &image.line_size, &image.endian);
	x = 1;
	while (x < 480)
	{
		my_pixel_put(&image, 640 / 2, x, 0x000FFFFFF);
		x++;
	}
	x = 1;
	while (x < 640)
	{
		my_pixel_put(&image, x, 480 / 2, 0x000FFFFFF);
		x++;
	}
	mlx_put_image_to_window(game.mlx, game.win, image.img_ptr, 0, 0);
	mlx_hook(game.win, 17, (1L<<17), close, &game);
	mlx_key_hook(game.win, ft_mlx_key_pressed, &game);
	mlx_loop(game.mlx);
}
