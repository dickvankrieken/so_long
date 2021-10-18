#include <stdio.h>
#include <fcntl.h>
#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/gnl/get_next_line.h"

void	store_map(t_map *map, char *argv)
{
	char	*line;
	int	fd;
	int	row;
	int	i;

	i = 0;
	row = 0;
	fd = open(argv, O_RDONLY);
	map->data = (char *)malloc(sizeof(char) * map->columns * map->rows + 1);
	if (!map->data)
		exit(EXIT_FAILURE);
	while (row < map->rows)
	{
		get_next_line(fd, &line);
		while (i < map->columns)
		{
			map->data[row * map->columns + i] = line[i];
			i++;
		}
		i = 0;
		row++;
	}
	map->data[row * map->columns + i] = '\0';
	ft_printf("%s", map->data);
}

void	validate_file_format(char *argv_map)
{
	int	len;

	len = ft_strlen(argv_map);
	if (ft_strncmp(argv_map + (len - 4), ".ber", 4) != 0)
	{
		ft_printf("%s\nError, the map must be a file ending with .ber", argv_map - len);
		exit(EXIT_FAILURE);
	}
}

void	parse(t_game *game, char *argv_map)
{
	validate_file_format(argv_map);
	validate_map_dimensions(game, argv_map);
	store_map(&game->map, argv_map);
}
