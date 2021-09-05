#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_img {
	void *img_ptr;
	char *address;
	int	bits_per_pixel;
	int	line_size;
	int	endian;
}	t_img;

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
}

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}

int	ft_mlx_key_pressed(int keycode, t_vars *vars)
{
	printf("keycode = %d", keycode);
}

void	my_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char	*dst;
	int	offset;

	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
	*(unsigned int *)dst = colour;
}

int	main(void)
{
	t_vars	vars;
	t_img	image;
	int	x;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	image.img_ptr = mlx_new_image(vars.mlx, 640, 480);
	image.address = mlx_get_data_addr(image.img_ptr, &image.bits_per_pixel, &image.line_size, &image.endian);
	x = 1;
	while (x < 480)
	{
		my_pixel_put(&image.img_ptr, 640 / 2, x, 0x000FFFFFF);
		x++;
	}
	x = 1;
	while (x < 640)
	{
		my_pixel_put(&image.img_ptr, x, 480 / 2, 0x000FFFFFF);
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img_ptr, 0, 0);
	mlx_hook(vars.win, 2, 1L<<17, close, &vars);
//	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
