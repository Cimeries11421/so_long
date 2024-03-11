#ifndef SO_LONG_H
# define SO_lONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"


# define X_W 1920
# define Y_W 1080

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
}			t_data;

typedef struct	s_map
{
	char **map;
}				t_map;

typedef struct s_textures
{
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*col;
	char	*path_player;
	char	*path_floor;
	char	*path_wall;
	char	*path_exit;
	char	*path_col;
	int		width;
	int		height;
}				t_textures;

typedef struct s_content
{
	int			pos_player[2];
	int			pos_floor[2];
	t_solong	so_long;
	t_textures	textures;		
	t_map		map;
}				t_content;

void	get_map(t_content *content);
int		key_press(int key, t_content *content);
void	store_textures(t_textures *textures, t_solong *so_long);
void	display_and_move_around(t_content *content);

#endif
