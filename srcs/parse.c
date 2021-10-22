/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 12:38:08 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/22 14:42:51 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/gnl/get_next_line.h"

static void	malloc_map_rows(t_map *map)
{
	int	i;

	i = 0;

	map->data = malloc(sizeof(char *) * map->rows);
	if (!map->data)
		exit(EXIT_FAILURE);
}

void	store_map_read_lines(t_map *map, int fd)
{
	char	*line;
	int		ret;
	int		row;

	row = 0;
	while (row < map->rows)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			free_map_data(map, row);
			ft_printf("Error\nThere was an issue reading the file");
			exit(EXIT_FAILURE);
		}
		map->data[row] = ft_strdup(line);
		free(line);
		row++;
	}
}

void	store_map(t_map *map, char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFailed to open map file");
		exit(EXIT_FAILURE);
	}
	malloc_map_rows(map);
	store_map_read_lines(map, fd);
}

void	validate_file_format(char *argv_map)
{
	int	len;

	len = ft_strlen(argv_map);
	if (ft_strncmp(argv_map + (len - 4), ".ber", 4) != 0)
	{
		ft_printf("Error\nThe map must be a file ending with .ber",
			argv_map - len);
		exit(EXIT_FAILURE);
	}
}

void	parse(t_game *game, char *argv_map)
{
	validate_file_format(argv_map);

	load_map_dimensions(game, argv_map);

	store_map(&game->map, argv_map);

	validate_map(game);

	if (game->map.player > 1)
	{
		multiple_to_one_player(game);
	}
}
