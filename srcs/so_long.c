/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 12:41:31 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/20 12:41:32 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

void	check_map_argument(int argc)
{
	if (argc < 2)
	{
		ft_printf("No map provided!");
		exit(0);
	}
	if (argc > 2)
	{
		ft_printf("Too many arguments!");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_map_argument(argc);
	game_init(&game);
	parse(&game, argv[1]);
	game.window.win = mlx_new_window(game.window.mlx, game.map.columns * 64,
			game.map.rows * 64, "so long");
	draw_map(&game);
	mlx_hook(game.window.win, 17, (1L << 17), close_window, &game.window);
	mlx_hook(game.window.win, 02, (1L << 0), hook_key_press, &game.window);
	mlx_loop(game.window.mlx);
}
