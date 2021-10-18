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

void	draw_map(t_game *game)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	game->img.img = mlx_xpm_file_to_image(game->window.mlx, "./assets/grass.xpm", &game->img.width, &game->img.height);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.line, &game->img.endian);
	while (i < game->map.rows)
	{
		while (j < game->map.columns)
		{
			mlx_put_image_to_window(game->window.mlx, game->window.win, game->img.img, j * 64, i * 64);
			if (game->map.data[i * game->map.rows + j] == 'P')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->player.img.img, j * 64, i * 64);

			j++;
		}
		j = 0;
		i++;
	}
}