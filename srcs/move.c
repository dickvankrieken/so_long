#include <mlx.h>
#include <stdlib.h>
#include "../includes/so_long.h"

void	player_move_up(t_game *game)
{
	check_empty_tile(game, -1, 0);
	check_collectible_tile(game, -1, 0);
	check_exit_tile(game, -1, 0);
}

void	player_move_down(t_game *game)
{
	check_empty_tile(game, 1, 0);
	check_collectible_tile(game, 1, 0);
	check_exit_tile(game, 1, 0);
}

void	player_move_left(t_game *game)
{
	check_empty_tile(game, 0, -1);
	check_collectible_tile(game, 0, -1);
	check_exit_tile(game, 0, -1);
}

void	player_move_right(t_game *game)
{
	check_empty_tile(game, 0, 1);
	check_collectible_tile(game, 0, 1);
	check_exit_tile(game, 0, 1);
}
