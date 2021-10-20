#include <fcntl.h>
#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/gnl/get_next_line.h"

void	malloc_map(t_map *map)
{
	int	i;

	i = 0;
	map->data = malloc(sizeof(char *) * map->rows);
	if (!map->data)
		exit(EXIT_FAILURE);
	while (i < map->rows)
	{
		map->data[i] = malloc(sizeof(char) * map->columns);
		if (!map->data[i])
		{
			free_map_data(map, i);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	store_map(t_map *map, char *argv)
{
	char	*line;
	int		fd;
	int		column;
	int		row;

	column = 0;
	row = 0;
	fd = open(argv, O_RDONLY);
	malloc_map(map);
	while (row < map->rows)
	{
		get_next_line(fd, &line);
		while (column < map->columns)
		{
			map->data[row][column] = line[column];
			column++;
		}
		column = 0;
		row++;
		free(line);
	}
}

void	validate_file_format(char *argv_map)
{
	int	len;

	len = ft_strlen(argv_map);
	if (ft_strncmp(argv_map + (len - 4), ".ber", 4) != 0)
	{
		ft_printf("%s\nError, the map must be a file ending with .ber",
			argv_map - len);
		exit(EXIT_FAILURE);
	}
}

void	parse(t_game *game, char *argv_map)
{
	validate_file_format(argv_map);
	validate_map_dimensions(game, argv_map);
	store_map(&game->map, argv_map);
}
