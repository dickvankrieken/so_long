#include "../so_long.h"

int	close(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
}

/* keycode 53 = escape key */
int	ft_mlx_key_pressed(int keycode, t_vars *vars)
{
	printf("keycode = %d", keycode);
    if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
}
