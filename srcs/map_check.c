/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 12:37:53 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/21 18:15:25 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

void	check_requirements(t_map map)
{
	if (map.exit == 0)
	{
		ft_printf("Error\nInvalid map, must contain an exit\n");
		exit(EXIT_FAILURE);
	}
	if (map.collectibles == 0)
	{
		ft_printf("Error\nInvalid map, must contain collectibles\n");
		exit(EXIT_FAILURE);
	}
	if (map.player == 0)
	{
		ft_printf("Error\nInvalid map, there must be one player\n");
		exit(EXIT_FAILURE);
	}
}

void	check_tiles(t_game *game, char *l)
{
	if (*l != '1')
	{
		/* er staat opeens niets meer op de plek waar de 0e pointer van de map.data array naar wijst */
		ft_printf("%s??", game->map.data[0]);
		ft_printf("Error\nWrong map format, not surrounded by only walls\n");
		exit(EXIT_FAILURE);
	}
	while (*l != '\0')
	{
		if (!(*l == '1' || *l == '0' || *l == 'C' || *l == 'E' || *l == 'P'))
		{
			ft_printf("Error\nInvalid map, contains invalid characters\n");
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
		ft_printf("Error\nWrong map format, not surrounded by only walls\n");
		exit(EXIT_FAILURE);
	}
}

void	line_is_walls(t_map map, char *line)
{

	while (*line != '\0')
	{
		if (*line != '1')
		{
			ft_printf("Error\nWrong map format, not surrounded by only walls\n");
//			free_map_data(&map, number);
//			while (1);
			exit(EXIT_FAILURE);
		}
		line++;
	}
}
