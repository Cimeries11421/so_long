#ifndef SO_LONG_H
# define SO_lONG_H

# include <stdio.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"


# define HEIGTH_W 1920;
# define WIDTH_W 1080;

typedef struct s_struct
{
	void		*mlx;
	void		*win;
}			t_solong;

typedef struct s_data
{

	void		*img;
	char		*addr;
	int			*bits_per_pixel;
	int			*size_line;
	int			*endian;
}				t_data;

#endif
