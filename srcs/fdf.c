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

void	init(t_frame *frame)
{
	frame->mlx = mlx_init();
	frame->win = mlx_new_window(frame->mlx, 640, 480, "fdf");
}


void	draw_fdf_image(t_frame *frame, t_img *image)
{
	int	x;

	image->img_ptr = mlx_new_image(frame->mlx, 640, 480);
	image->address = mlx_get_data_addr(image->img_ptr, &image->bits_per_pixel, &image->line_size, &image->endian);
	x = 1;
	while (x < 480)
	{
		my_pixel_put(image, 640 / 2, x, 0x000FFFFFF);
		x++;
	}
	x = 1;
	while (x < 640)
	{
		my_pixel_put(image, x, 480 / 2, 0x000FFFFFF);
		x++;
	}
	mlx_put_image_to_window(frame->mlx, frame->win, image->img_ptr, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	t_frame frame;
	t_img	image;

	check_map_argument(argc);
	parse(&fdf);
	init(&frame);
	draw_fdf_image(&frame, &image);
	attach_hooks(&frame);
	mlx_loop(frame.mlx);
}
