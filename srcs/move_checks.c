#include <mlx.h>
#include <stdlib.h>
#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

void	check_collectible_tile(t_game *game, int move_y, int move_x)
{
	if (game->map.data[game->player.y + move_y][game->player.x + move_x] == 'C')
	{
		game->map.data[game->player.y + move_y][game->player.x + move_x] = 'P';
		game->map.data[game->player.y][game->player.x] = '0';
		game->map.collectibles--;
		game->player.moves++;
		ft_printf("Move %d\n", game->player.moves);
		draw_map(game);
	}
}

void	check_empty_tile(t_game *game, int move_y, int move_x)
{
	if (game->map.data[game->player.y + move_y][game->player.x + move_x] == '0')
	{
		game->map.data[game->player.y + move_y][game->player.x + move_x] = 'P';
		game->map.data[game->player.y][game->player.x] = '0';
		game->player.moves++;
		ft_printf("Move %d\n", game->player.moves);
		draw_map(game);
	}
}

void	check_exit_tile(t_game *game, int move_y, int move_x)
{
	if (game->map.data[game->player.y + move_y][game->player.x + move_x] == 'E'
			&& game->map.collectibles == 0)
	{
		game->map.data[game->player.y + move_y][game->player.x + move_x] = 'P';
		game->map.data[game->player.y][game->player.x] = '0';
		game->player.moves++;
		ft_printf("Move %d\n", game->player.moves);
		draw_map(game);
		free_map_data(&game->map, game->map.rows);
		exit(EXIT_SUCCESS);
	}
}
