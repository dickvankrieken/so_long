#include <fcntl.h>
#include <stdlib.h>
#include "../so_long.h"
#include "../libft/includes/ft_printf.h"

void	check_requirements(t_game *game)
{
	if (game->map.exit == 0)
	{
		ft_printf("Error, invalid map, must contain an exit\n");
		exit(EXIT_FAILURE);
	}
	if (game->map.collectibles == 0)
	{
		ft_printf("Error, invalid map, must contain collectibles\n");
		exit(EXIT_FAILURE);
	}
	if (game->map.player != 1)
	{
		ft_printf("Error, invalid map, there must be one player\n");
		exit(EXIT_FAILURE);
	}
}

void	check_tiles(t_game *game, char *l)
{
	if (*l != '1')
	{
		ft_printf("Error, wrong map format, not surrounded by only walls\n");
		exit(EXIT_FAILURE);
	}
	while (*l != '\0')
	{
		if (!(*l == '1' || *l == '0' || *l == 'C' || *l == 'E' || *l == 'P'))
		{
			ft_printf("Error, invalid map, contains invalid characters\n");
			exit(EXIT_FAILURE);
		}
		if (*l == 'E')
			game->map.exit++;
		if (*l == 'C')
			game->map.collectibles++;
		if (*l == 'P')
			game->map.player++;
		l++;
	}
	if (*(l - 1) != '1')
	{
		ft_printf("Error, wrong map format, not surrounded by only walls\n");
		exit(EXIT_FAILURE);
	}
}

void	line_is_walls(char *line)
{
	while (*line != '\0')
	{
		if (*line != '1')
		{
			ft_printf("Error, wrong map format, not surrounded by only walls\n");
			exit(EXIT_FAILURE);
		}
		line++;
	}
}
