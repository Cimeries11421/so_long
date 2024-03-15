#include "so_long.h"

void	display_map(t_content *content)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (content->map.map[y])
	{
		while (content->map.map[y][x])
		{
			if(content->map.map[y][x] == '1')
			{
				mlx_put_image_to_window(content->so_long.mlx, content->so_long.win, 
						content->textures.wall, (x * 32), (y *32));
			}
			else if (content->map.map[y][x] == '0')
			{
				mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
						content->textures.floor, (x * 32), (y * 32));
			}
			else if(content->map.map[y][x] == 'P')
			{
				mlx_put_image_to_window(content->so_long.mlx, content->so_long.win, 
						content->textures.player, (x * 32), (y * 32));
				content->pos_player[0] = x * 32;
				content->pos_player[1] = y * 32;
			}
			else if(content->map.map[y][x] == 'C')
			{
				mlx_put_image_to_window(content->so_long.mlx, content->so_long.win, 
						content->textures.col, (x * 32), (y * 32));
			}
			else if(content->map.map[y][x] == 'E')
			{
				mlx_put_image_to_window(content->so_long.mlx, content->so_long.win, 
					content->textures.exit, (x * 32), (y *32));
			}
			x++;
		}
		x = 0;
		y++;
	}
}

static void	count_collectibles(t_content *content)
{
	size_t	y;
	
	y = 0;
	content->map.nbr_col = 0;
	while (content->map.map[y])
	{
		if(ft_strchr(content->map.map[y], 'C'))
			content->map.nbr_col++;
		y++;
	}
	printf("C = %d\n", content->map.nbr_col);
	content->map.count = 0;
}

static int	check_extension(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
		i++;
	if (arg[i - 1] != 'r')
		return (-1);
	if (arg[i - 2] != 'e')
		return (-1);
	if (arg[i - 3] != 'b')
		return (-1);
	if (arg[i - 4] != '.')
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_content	content;
	t_solong	so_long;
	t_textures	textures;
	
	if (ac != 2)
	{
		write(2, "Error : only 1 argument\n", 25);
		return (-1);
	}
	if (check_extension(av[1]) != 0)
	{
		write(2, "Error : wrong extension file", 28);
		return (-1);
	}

	content.so_long = (t_solong){0};
	content.map = (t_map){0};
	content.textures = (t-textures){0};
	get_map(&content, av);
	printf("COUCOU %p, %p, %p\n", content.textures.player, content.so_long.mlx, content.textures.exit);
	content.so_long = (t_solong){0}; 
	content.so_long.mlx = mlx_init(); //etablished a connection with the server
									  //+ malloc big struct, display.
	if (!content.so_long.mlx)
	{
		write (2, "Error : mlx_init\n", 18);
		return (-1);
	}
	content.so_long.win = mlx_new_window(content.so_long.mlx, content.map.size_x, content.map.size_y,
			"JEU_VIDEAL");
	if (!content.so_long.win)
	{
		write (2, "Error : mlx_new_window\n", 16);
		mlx_destroy_display(content.so_long.mlx);
		free(content.so_long.mlx);
		return (-1);
	}
	store_textures(&(content.textures), &(content.so_long));
	display_map(&content);
	count_collectibles(&content);
	display_and_move_around(&content);
	mlx_loop(content.so_long.mlx); //function that keeps the process alive
//	mlx_destroy_window(content->so_long.mlx, so_long.win); //apres la loop pour tour free.
	//lx_destroy_display(content->so_long.mlx);
	//free(content->so_long.mlx);
}
