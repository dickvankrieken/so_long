/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 12:32:02 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/10/21 18:14:42 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* structs */
typedef struct s_window {
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_map {
	char	**data;
	int		columns;
	int		rows;
	int		collectibles;
	int		player;
	int		exit;
}	t_map;

typedef struct s_player {
	int	x;
	int	y;
	int	moves;
}	t_player;

typedef struct s_game {
	t_window	window;
	t_player	player;
	t_img		g_img;
	t_img		p_img;
	t_img		c_img;
	t_img		w_img;
	t_img		e_img;
	t_map		map;
}	t_game;

/* function prototypes */
/* hooks.c */
int		close_window(t_game *game);
int		hook_key_press(int keycode, t_game *game);

/* parse.c */
void	parse(t_game *game, char *map);

/* game.c */
int		game_loop(t_game *game);
void	game_init(t_game *game);
void	game_vars_init(t_game *game);

/* map.c */
void	load_map_dimensions(t_game *game, char *argv_map);
void	draw_map(t_game *game);
void	free_map_data(t_map *map, int number);

/* map_check.c */
void	check_requirements(t_map map);
void	check_tiles(t_game *game, char *l);
void	line_is_walls(t_map map, char *line);

/* map_check2.c */
void	multiple_to_one_player(t_game *game);
void	validate_map(t_game *game);

/* move.c */
void	player_move_up(t_game *game);
void	player_move_down(t_game *game);
void	player_move_left(t_game *game);
void	player_move_right(t_game *game);

/* move_checks.c */
int		check_collectible_tile(t_game *game, int move_y, int move_x);
int		check_empty_tile(t_game *game, int move_y, int move_x);
int		check_exit_tile(t_game *game, int move_y, int move_x);

#endif
