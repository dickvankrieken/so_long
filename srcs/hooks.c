#include <stdlib.h>
#include <mlx.h>
#include "../fdf.h"

int	close(int keycode, t_frame *frame)
{
	(void)keycode;
	(void)frame;
	exit(0);
}

/* keycode 53 = escape key */
int	ft_mlx_key_pressed(int keycode, t_frame *frame)
{
    if (keycode == ESC)
	{
		mlx_destroy_window(frame->mlx, frame->win);
		exit(0);
	}
	return (0);
}

void	attach_hooks(t_frame *frame)
{
	mlx_hook(frame->win, 17, (1L<<17), close, frame);
	mlx_key_hook(frame->win, ft_mlx_key_pressed, frame);
}
