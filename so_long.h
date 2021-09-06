#ifndef SO_LONG_H
# define SO_LONG_H


typedef struct	s_game {
	void	*mlx;
	void	*win;
}				t_game;

typedef struct	s_img {
	void *img_ptr;
	char *address;
	int	bits_per_pixel;
	int	line_size;
	int	endian;
}	t_img;

int	close(int keycode, t_game *vars);
int ft_mlx_key_pressed(int keycode, t_game *vars);

#endif