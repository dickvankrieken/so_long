#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "../fdf.h"
#include "../libft/includes/ft_printf.h"

void	my_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char	*dst;
	int	offset;

	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
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

void	init_mlx(t_frame *frame)
{
	frame->mlx = mlx_init();
}

int	main(int argc, char **argv)
{
	t_frame frame;
	t_img	image;
	int	x;

	check_map_argument(argc);
	init_mlx(&frame);


	frame.win = mlx_new_window(frame.mlx, 640, 480, "fdf");
	image.img_ptr = mlx_new_image(frame.mlx, 640, 480);
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
	mlx_put_image_to_window(frame.mlx, frame.win, image.img_ptr, 0, 0);
	mlx_hook(frame.win, 17, (1L<<17), close, &frame);
	mlx_key_hook(frame.win, ft_mlx_key_pressed, &frame);
	mlx_loop(frame.mlx);
}
