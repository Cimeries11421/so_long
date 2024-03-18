/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:00:27 by ebriere           #+#    #+#             */
/*   Updated: 2024/03/18 22:38:58 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_extension(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
		i++;
	if (i < 4)
		return (-1);
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

	content.so_long = (t_solong){0};
	content.map = (t_map){0};
	content.textures = (t_textures){0};
	if (av[1] && open(av[1], O_DIRECTORY) != -1)
		error_exit(&content, "Error : WHY A DIRECTORY\n", close(3) || 1);
	if (ac != 2)
		error_exit(&content, "Error : only 1 argument required\n", 1);
	if (check_extension(av[1]) != 0)
		error_exit(&content, "Error : wrong extension file\n", 1);
	get_map(&content, av);
	content.so_long.mlx = mlx_init();
	if (!content.so_long.mlx)
		error_exit(&content, "Error : mlx_init", 1);
	content.so_long.win = mlx_new_window(content.so_long.mlx,
			content.map.size_x, content.map.size_y, "Red Girl");
	if (!content.so_long.win)
		error_exit(&content, "Error : mlx_new_window\n", 1);
	store_textures(&content);
	display_map(&content);
	count_collectibles(&content);
	display_and_move_around(&content);
	mlx_hook(content.so_long.win, 17, 1L << 0, free_and_exit, &content);
	mlx_loop(content.so_long.mlx);
}
