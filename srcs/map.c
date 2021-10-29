/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 12:37:46 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/29 13:14:25 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include "../includes/so_long.h"
#include "../libft/includes/get_next_line.h"
#include "../libft/includes/ft_printf.h"

static void	put_images_set_player_coordinates(t_game *d, int i, int j)
{
	mlx_put_image_to_window(d->window.mlx, d->window.win,
		d->g_img.img, j * 64, i * 64);
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

void	load_map_dimensions(t_game *game, char *argv_map)
{
	char	*line;
	int		ret;
	int		fd;

	game_vars_init(game);
	fd = open(argv_map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFailed to open map file");
		exit(EXIT_FAILURE);
	}
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			free_map_data(&game->map, game->map.rows);
			ft_printf("Error\nThere was an issue reading the file");
			exit(EXIT_FAILURE);
		}
		game->map.rows++;
		free(line);
	}
}

void	free_map_data(t_map *map, int number)
{
	int	i;

	i = 0;
	while (number > 0 && i < number)
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
