#ifndef FDF_H
# define FDF_H

/* macros for x11 keypress numbers */
# define ESC 53

/* structs */
typedef struct s_window {
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_img {
	void	*img;
	char	*address;
	int		bpp;
	int		line;
	int		endian;
}	t_img;

typedef struct s_map {
	int *map_values;
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
int		ft_mlx_key_pressed(int keycode, t_game *game);

/* parse.c */
void	parse(t_game *game, char *map);

/* map.c */
void	validate_map_dimensions(t_game *game, char *argv_map);

#endif
