#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/so_long.h"
#include "../includes/keycodes.h"
#include "../libft/includes/ft_printf.h"

int	game_loop(t_game *game)
{
	if (game->update)
	{
		ft_printf("test");
		game->update = 0;
	}
	 return (0);
}

void	game_init(t_game *d)
{
	d->window.mlx = mlx_init();
	d->update = 0;
	d->player.img.img = mlx_xpm_file_to_image(d->window.mlx, "./assets/player.xpm", &d->player.img.width, &d->player.img.height);
	d->player.img.addr = mlx_get_data_addr(d->player.img.img, &d->player.img.bpp, &d->player.img.line, &d->player.img.endian);
}