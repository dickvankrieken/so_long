/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 12:32:35 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/22 16:22:18 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/so_long.h"

void	game_vars_init(t_game *game)
{
	game->map.exit = 0;
	game->map.collectibles = 0;
	game->map.player = 0;
	game->map.rows = 0;
	game->map.columns = 0;
	game->player.moves = 0;
}

void	game_init(t_game *d)
{
	d->window.mlx = mlx_init();
	d->g_img.img = mlx_xpm_file_to_image(d->window.mlx, "./assets/grass.xpm",
			&d->g_img.width, &d->g_img.height);
	d->g_img.addr = mlx_get_data_addr(d->g_img.img, &d->g_img.bpp,
			&d->g_img.line, &d->g_img.endian);
	d->p_img.img = mlx_xpm_file_to_image(d->window.mlx, "./assets/player.xpm",
			&d->p_img.width, &d->p_img.height);
	d->p_img.addr = mlx_get_data_addr(d->p_img.img, &d->p_img.bpp,
			&d->p_img.line, &d->p_img.endian);
	d->w_img.img = mlx_xpm_file_to_image(d->window.mlx, "./assets/tree.xpm",
			&d->w_img.width, &d->w_img.height);
	d->w_img.addr = mlx_get_data_addr(d->w_img.img, &d->w_img.bpp,
			&d->w_img.line, &d->w_img.endian);
	d->c_img.img = mlx_xpm_file_to_image(d->window.mlx, "./assets/coins.xpm",
			&d->c_img.width, &d->c_img.height);
	d->c_img.addr = mlx_get_data_addr(d->w_img.img, &d->w_img.bpp,
			&d->c_img.width, &d->c_img.height);
	d->e_img.img = mlx_xpm_file_to_image(d->window.mlx, "./assets/exit.xpm",
			&d->e_img.width, &d->e_img.height);
	d->e_img.addr = mlx_get_data_addr(d->e_img.img, &d->e_img.bpp,
			&d->e_img.width, &d->e_img.height);
}
