#include <stdio.h>
#include <fcntl.h>
#include "../so_long.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/gnl/get_next_line.h"

/*
void	malloc_map_values(t_game *game)
{
	game->map.numbers = (int *)malloc(sizeof(int *) * (game->map.columns * game->map.rows));
}
*/

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
	char	*line;
	int		fd;
	int		ret;

	validate_file_format(argv_map);
	validate_map_dimensions(game, argv_map);
//	malloc_map_values(game);
	fd = open(argv_map, O_RDONLY);
	ret = get_next_line(fd, &line);
	ft_printf("%s\n", line);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		ft_printf("%s\n", line);
	}
}
