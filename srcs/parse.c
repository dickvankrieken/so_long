#include "../fdf.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/gnl/get_next_line.h"

int	parse(t_fdf *fdf)
{
	char *line;
	/* hoe gebruik je get next line om lines uit een file te lezen? */
	int fd;

	fd = open();
	while (get_next_line(1, &line))
	{
		ft_printf("%s", line);
	}
}
