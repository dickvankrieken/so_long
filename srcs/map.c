#include <fcntl.h>
#include "../so_long.h"
#include "../libft/gnl/get_next_line.h"
#include "../libft/includes/ft_printf.h"

static void	map_init(t_game *game)
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

	map_init(game);
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
