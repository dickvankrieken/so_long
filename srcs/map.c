/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 12:37:46 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/20 12:37:48 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "../includes/so_long.h"
#include "../libft/gnl/get_next_line.h"
#include "../libft/includes/ft_printf.h"

static void	game_vars_init(t_game *game)
{
	game->map.exit = 0;
	game->map.collectibles = 0;
	game->map.player = 0;
	game->player.moves = 0;
}

static void	put_images_set_player_coordinates(t_game *d, int i, int j)
{
	mlx_put_image_to_window(d->window.mlx, d->window.win,
		d->img.img, j * 64, i * 64);
	if (d->map.data[i][j] == 'P')
	{
		mlx_put_image_to_window(d->window.mlx, d->window.win,
			d->p_img.img, j * 64, i * 64);
		d->player.x = j;
		d->player.y = i;
	}
	if (d->map.data[i][j] == '1')
		mlx_put_image_to_window(d->window.mlx, d->window.win,
			d->w_img.img, j * 64, i * 64);
	if (d->map.data[i][j] == 'C')
		mlx_put_image_to_window(d->window.mlx, d->window.win,
			d->c_img.img, j * 64, i * 64);
	if (d->map.data[i][j] == 'E')
		mlx_put_image_to_window(d->window.mlx, d->window.win,
			d->e_img.img, j * 64, i * 64);
}

void	validate_map_dimensions(t_game *game, char *argv_map)
{
	char	*line;
	int		ret;
	int		fd;

	game_vars_init(game);
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

void	free_map_data(t_map *map, int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
}

void	draw_map(t_game *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	d->img.img = mlx_xpm_file_to_image(d->window.mlx, "./assets/grass.xpm",
			&d->img.width, &d->img.height);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp,
			&d->img.line, &d->img.endian);
	while (i < d->map.rows)
	{
		while (j < d->map.columns)
		{
			put_images_set_player_coordinates(d, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}
