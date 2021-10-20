/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 12:32:35 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/20 12:32:37 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/so_long.h"
#include "../includes/keycodes.h"
#include "../libft/includes/ft_printf.h"

void	game_init(t_game *d)
{
	d->window.mlx = mlx_init();
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
