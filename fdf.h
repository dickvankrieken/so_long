#ifndef FDF_H
# define FDF_H

# define ESC 53

typedef struct s_frame {
	void	*mlx;
	void	*win;
}				t_frame;

typedef struct s_map {
	int	width;
	int	height;
}	t_map;

typedef struct s_img {
	void	*img_ptr;
	char	*address;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_fdf {
	struct s_frame	frame;
	struct s_map	map;
}	t_fdf;

/* hooks.c */
void	attach_hooks(t_frame *frame);
int		close(int keycode, t_frame *vars);
int		ft_mlx_key_pressed(int keycode, t_frame *vars);

/* parse.c */
int		parse(t_fdf *fdf);


#endif
