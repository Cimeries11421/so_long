/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:00:27 by ebriere           #+#    #+#             */
/*   Updated: 2024/03/17 20:00:29 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_image_in_map(t_content *content, char type, int y, int x)
{

	if (type == '1')
		mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
			content->textures.wall, (x * SIZE_IMAGE), (y * SIZE_IMAGE));
	if (type == '0')
		mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
			content->textures.floor, (x * SIZE_IMAGE), (y * SIZE_IMAGE));
	if (type == 'P')
	{
		mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
			content->textures.player, (x * SIZE_IMAGE), (y * SIZE_IMAGE));
		content->pos_player[0] = x * SIZE_IMAGE;
		content->pos_player[1] = y * SIZE_IMAGE;
	}
	if (type == 'C')
		mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
			content->textures.col, (x * SIZE_IMAGE), (y * SIZE_IMAGE));
	if (type == 'E')
		mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
			content->textures.exit, (x * SIZE_IMAGE), (y * SIZE_IMAGE));
}

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
			if (content->map.map[y][x] == '1')
				display_image_in_map(content, '1', y, x);
			else if (content->map.map[y][x] == '0')
				display_image_in_map(content, '0', y, x);
			else if (content->map.map[y][x] == 'P')
				display_image_in_map(content, 'P', y, x);
			else if (content->map.map[y][x] == 'C')
				display_image_in_map(content, 'C', y, x);
			else if (content->map.map[y][x] == 'E')
				display_image_in_map(content, 'E', y, x);
			x++;
			//usleep(50000);
			//mlx_do_sync(content->so_long.mlx);
		}
		x = 0;
		y++;
	}
}

static void	count_collectibles(t_content *content)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	content->map.nbr_col = 0;
	while (content->map.map[y])
	{
		while (content->map.map[y][x])
		{
			if (content->map.map[y][x] == 'C')
			{
				content->map.nbr_col++;
			}
			x++;
		}
		x = 0;
		y++;
	}
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

	content.so_long = (t_solong){0};
	content.map = (t_map){0};
	content.textures = (t_textures){0};
	if (ac != 2)
		error_exit(&content, "Error : only 1 argument required\n", 1);
	if (check_extension(av[1]) != 0)
		error_exit(&content, "Error : wrong extension file\n", 1);
	get_map(&content, av);
	content.so_long.mlx = mlx_init();
	if (!content.so_long.mlx)
		error_exit(&content, "Error : mlx_init", 1);
	content.so_long.win = mlx_new_window(content.so_long.mlx,
			content.map.size_x, content.map.size_y, "JEU_VIDEAL");
	if (!content.so_long.win)
		error_exit(&content, "Error : mlx_new_window\n", 1);
	store_textures(&content);
	display_map(&content);
	count_collectibles(&content);
	display_and_move_around(&content);
    mlx_hook(content.so_long.win, 17, 1L<<0, free_and_exit, &content); 
	mlx_loop(content.so_long.mlx);
//	sleep(5);
//	free_and_exit(&content, 0);
}
