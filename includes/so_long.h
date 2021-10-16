#ifndef FDF_H
# define FDF_H

/* structs */
typedef struct s_window {
	void	*mlx;
	void	*win;
}	t_window;

// IMAGES
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
	char **data;
	int	columns;
	int rows;
	int collectibles;
	int player;
	int exit;
}	t_map;

typedef struct s_game {
	t_window	window;
	t_img		img;
	t_map		map;
}	t_game;

/* function prototypes */
/* hooks.c */
int		close_window(t_game *game);
int		hook_key_press(int keycode, t_game *game);

/* parse.c */
void	parse(t_game *game, char *map);

/* map.c */
void	validate_map_dimensions(t_game *game, char *argv_map);

/* map_checks.c */
void	check_requirements(t_game *game);
void	check_tiles(t_game *game, char *l);
void	line_is_walls(char *line);

#endif
