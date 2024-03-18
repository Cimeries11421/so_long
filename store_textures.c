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

void	assign_player_exit_to_pointer(t_content *content)
{
	content->textures.player = mlx_xpm_file_to_image(content->so_long.mlx,
			content->textures.path_player, &content->textures.width,
			&content->textures.height);
	if (!content->textures.player)
		error_exit(content, "Error : mlx_xmp_file_to_image", 1);
	content->textures.exit = mlx_xpm_file_to_image(content->so_long.mlx,
			content->textures.path_exit, &content->textures.width,
			&content->textures.height);
	if (!content->textures.exit)
		error_exit(content, "Error : mlx_xmp_file_to_image", 1);
}

void	assign_floor_wall_col_to_pointer(t_content *content)
{
	content->textures.col = mlx_xpm_file_to_image(content->so_long.mlx,
			content->textures.path_col, &content->textures.width,
			&content->textures.height);
	if (!content->textures.col)
		error_exit(content, "Error : mlx_xmp_file_to_image", 1);
	content->textures.floor = mlx_xpm_file_to_image(content->so_long.mlx,
			content->textures.path_floor, &content->textures.width,
			&content->textures.height);
	if (!content->textures.floor)
		error_exit(content, "Error : mlx_xmp_file_to_image", 1);
	content->textures.wall = mlx_xpm_file_to_image(content->so_long.mlx,
			content->textures.path_wall, &content->textures.width,
			&content->textures.height);
	if (!content->textures.wall)
		error_exit(content, "Error : mlx_xmp_file_to_image", 1);
}

void	store_textures(t_content *content)
{
	init_path(content);
	assign_floor_wall_col_to_pointer(content);
	assign_player_exit_to_pointer(content);
}
