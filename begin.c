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

int	main(int ac, char **av)
{
	t_data		img;
	t_content	content;


	if (ac != 2)
	{
		write(2, "Error : only 1 argument\n", 25);
		return (-1);
	}
	//content->so_long = (t_so_long){0};
	content.so_long = (t_solong){0}; 
	content.so_long.mlx = mlx_init(); //etablished a connection with the server
									  //+ malloc big struct, display.
	if (!content.so_long.mlx)
	{
		write (2, "Error : mlx_init\n", 16);
		return (-1);
	}
	content.so_long.win = mlx_new_window(content.so_long.mlx, X_W , Y_W, "JEU_VIDEAL");
	if (!content.so_long.win)
	{
		write (2, "Error : mlx_new_window\n", 16);
		mlx_destroy_display(content.so_long.mlx);
		free(content.so_long.mlx);
		return (-1);
	}
	img.img = mlx_new_image(content.so_long.mlx, 1920, 1080); // A quoi cela sert ? 
	store_textures(&(content.textures), &(content.so_long));
	get_map(&content, av);
	display_map(&content);
	count_collectibles(&content);
	//img.addr = mlx_get_data_addr(img.img, img.bits_per_pixel, img.size_line, img.endian);
	display_and_move_around(&content);
	mlx_loop(content.so_long.mlx); //function that keeps the process alive
	//mlx_destroy_window(content->so_long.mlx, so_long.win); //apres la loop pour tour free.
	//lx_destroy_display(content->so_long.mlx);
	//free(content->so_long.mlx);
}
