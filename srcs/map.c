#include <mlx.h>
#include <fcntl.h>
#include "../includes/so_long.h"
#include "../libft/gnl/get_next_line.h"
#include "../libft/includes/ft_printf.h"

static void	map_vars_init(t_game *game)
{
	game->map.exit = 0;
	game->map.collectibles = 0;
	game->map.player = 0;
}

void	validate_map_dimensions(t_game *game, char *argv_map)
{
	char	*line;
	int		ret;
	int		fd;

	map_vars_init(game);
	fd = open(argv_map, O_RDONLY);
	ret = get_next_line(fd, &line);
	line_is_walls(line);
	game->map.columns = ft_strlen(line);
	game->map.rows = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		check_tiles(game, line);
		if (ft_strlen(line) != game->map.columns)
		{
			ft_printf("Error, map is not rectangular\n");
			exit(EXIT_FAILURE);
		}
		game->map.rows++;
	}
	check_requirements(game);
	line_is_walls(line);
}

void	draw_map(t_game *d)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	d->img.img = mlx_xpm_file_to_image(d->window.mlx, "./assets/grass.xpm", &d->img.width, &d->img.height);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp, &d->img.line, &d->img.endian);
	while (i < d->map.rows)
	{
		while (j < d->map.columns)
		{
			mlx_put_image_to_window(d->window.mlx, d->window.win, d->img.img, j * 64, i * 64);
			if (d->map.data[i * d->map.columns + j] == 'P')
			 	mlx_put_image_to_window(d->window.mlx, d->window.win, d->p_img.img, j * 64, i * 64);
			if (d->map.data[i * d->map.columns + j] == '1')
			 	mlx_put_image_to_window(d->window.mlx, d->window.win, d->w_img.img, j * 64, i * 64);
			if (d->map.data[i * d->map.columns + j] == 'C')
			 	mlx_put_image_to_window(d->window.mlx, d->window.win, d->c_img.img, j * 64, i * 64);
			if (d->map.data[i * d->map.columns + j] == 'E')
			 	mlx_put_image_to_window(d->window.mlx, d->window.win, d->e_img.img, j * 64, i * 64);			j++;
		}
		j = 0;
		i++;
	}
}