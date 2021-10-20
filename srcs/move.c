#include <mlx.h>
#include "../includes/so_long.h"

void	player_move_up(t_game *game)
{
	if (check_empty_tile(game, -1, 0))
		return ;
	else if (check_collectible_tile(game, -1, 0))
		return ;
	else if (check_exit_tile(game, -1, 0))
		return ;
}

void	player_move_down(t_game *game)
{
	if (check_empty_tile(game, 1, 0))
		return ;
	else if (check_collectible_tile(game, 1, 0))
		return ;
	else if (check_exit_tile(game, 1, 0))
		return ;
}

void	player_move_left(t_game *game)
{
	if (check_empty_tile(game, 0, -1))
		return ;
	if (check_collectible_tile(game, 0, -1))
		return ;
	if (check_exit_tile(game, 0, -1))
		return ;
}

void	player_move_right(t_game *game)
{
	if (check_empty_tile(game, 0, 1))
		return ;
	if (check_collectible_tile(game, 0, 1))
		return ;
	if (check_exit_tile(game, 0, 1))
		return ;
}
