/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:44:22 by ebriere           #+#    #+#             */
/*   Updated: 2024/03/18 18:44:23 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_image_in_map(t_content *content, char type, int y, int x)
{
	if (type == '1')
		mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
			content->textures.wall, (x * SIZE_IMAGE), (y * SIZE_IMAGE));
	if (type == '0')
	{
		mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
			content->textures.floor, (x * SIZE_IMAGE), (y * SIZE_IMAGE));
		content->pos_floor[0] = x * SIZE_IMAGE;
		content->pos_floor[1] = y * SIZE_IMAGE;
	}
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
		}
		x = 0;
		y++;
	}
}

void	count_collectibles(t_content *content)
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
