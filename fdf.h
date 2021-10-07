#ifndef FDF_H
# define FDF_H


typedef struct	s_frame {
	void	*mlx;
	void	*win;
}				t_frame;

typedef struct	s_img {
	void *img_ptr;
	char *address;
	int	bits_per_pixel;
	int	line_size;
	int	endian;
}	t_img;

int	close(int keycode, t_frame *vars);
int ft_mlx_key_pressed(int keycode, t_frame *vars);

#endif
