#include "so_long.h"

static void	init_path(t_textures *textures)
{
	textures->path_player = "./Player.xpm";
	textures->path_col = "./col.xpm";
	textures->path_floor = "./floor.xpm";
	textures->path_wall = "./wall.xpm";
	textures->path_exit = "./exit.xpm";
}

void	store_textures(t_textures *textures, t_solong *so_long)
{
	init_path(textures);	
//	printf("height = %d\n", textures->height);
	textures->player = mlx_xpm_file_to_image(so_long->mlx, textures->path_player,
						&textures->width, &textures->height);
	if (!textures->player)
		exit(-1); //ft free, mlx_destoy, exit
	textures->col = mlx_xpm_file_to_image(so_long->mlx, textures->path_col,
						&textures->width, &textures->height);
	if (!textures->col)
		exit(-1); //
	textures->floor = mlx_xpm_file_to_image(so_long->mlx, textures->path_floor,
						&textures->width, &textures->height);
	if (!textures->floor)
		exit(-1); //
	textures->wall = mlx_xpm_file_to_image(so_long->mlx, textures->path_wall,
						&textures->width, &textures->height);
	if (!textures->wall)
	exit(-1); //
	textures->exit = mlx_xpm_file_to_image(so_long->mlx, textures->path_exit,
						&textures->width, &textures->height);
	if (!textures->exit)
		exit(-1); //	
}
