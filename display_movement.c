/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:58:04 by ebriere           #+#    #+#             */
/*   Updated: 2024/03/18 21:58:06 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_image(int display_exit, t_content *content)
{
	if (display_exit == 1)
	{
		mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
			content->textures.exit, content->pos_floor[0],
			content->pos_floor[1]);
	}
	else if (display_exit == 0)
	{
		mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
			content->textures.floor, content->pos_floor[0],
			content->pos_floor[1]);
	}
	mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
		content->textures.player, content->pos_player[0],
		content->pos_player[1]);
}
