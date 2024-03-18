/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:01:15 by ebriere           #+#    #+#             */
/*   Updated: 2024/03/17 20:01:17 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_path(t_content *content)
{
	content->textures.path_player = "./textures/player.xpm";
	content->textures.path_col = "./textures/col.xpm";
	content->textures.path_floor = "./textures/floor.xpm";
	content->textures.path_wall = "./textures/wall.xpm";
	content->textures.path_exit = "./textures/exit.xpm";
}

void	store_textures(t_content *content)
{
	init_path(content);
	content->textures.player = mlx_xpm_file_to_image(content->so_long.mlx,
			content->textures.path_player, &content->textures.width, &content->textures.height);
	if (!content->textures.player)
		error_exit(content, "Error : mlx_xmp_file_to_image", 1);
	content->textures.col = mlx_xpm_file_to_image(content->so_long.mlx, content->textures.path_col,
			&content->textures.width, &content->textures.height);
	if (!content->textures.col)
		error_exit(content, "Error : mlx_xmp_file_to_image", 1);
	content->textures.floor = mlx_xpm_file_to_image(content->so_long.mlx, content->textures.path_floor,
			&content->textures.width, &content->textures.height);
	if (!content->textures.floor)
		error_exit(content, "Error : mlx_xmp_file_to_image", 1);
	content->textures.wall = mlx_xpm_file_to_image(content->so_long.mlx, content->textures.path_wall,
			&content->textures.width, &content->textures.height);
	if (!content->textures.wall)
		error_exit(content, "Error : mlx_xmp_file_to_image", 1);
	content->textures.exit = mlx_xpm_file_to_image(content->so_long.mlx, content->textures.path_exit,
			&content->textures.width, &content->textures.height);
	if (!content->textures.exit)
		error_exit(content, "Error : mlx_xmp_file_to_image", 1);
}

void	display_image(int display_exit, t_content *content)
{
	if (display_exit == 1)
	{
		mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
			content->textures.exit, content->pos_floor[0],
			content->pos_floor[1]);
	}
	else
		mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
			content->textures.floor, content->pos_floor[0],
			content->pos_floor[1]);
	mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
		content->textures.player, content->pos_player[0],
		content->pos_player[1]);
}
