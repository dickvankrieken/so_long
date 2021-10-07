#include <stdlib.h>
#include <mlx.h>
#include "../fdf.h"
#include "../libft/includes/ft_printf.h"

int	close(int keycode, t_frame *frame)
{
	(void)keycode;
	(void)frame;
	exit(0);
}

/* keycode 53 = escape key */
int	ft_mlx_key_pressed(int keycode, t_frame *frame)
{
	ft_printf("keycode = %d", keycode);
    if (keycode == 53)
	{
		mlx_destroy_window(frame->mlx, frame->win);
		exit(0);
	}
	return (0);
}
