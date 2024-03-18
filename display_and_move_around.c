/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_and_move_around.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:00:34 by ebriere           #+#    #+#             */
/*   Updated: 2024/03/17 20:00:35 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_and_wall_collision(char key, int y, int x, t_content *content)
{
	if (key == 'w')
	{
		if (content->map.map[y - 1][x] != '1')
			content->pos_player[1] -= SIZE_IMAGE;
	}
	else if (key == 's')
	{
		if (content->map.map[y + 1][x] != '1')
			content->pos_player[1] += SIZE_IMAGE;
	}
	else if (key == 'd')
	{
		if (content->map.map[y][x + 1] != '1')
			content->pos_player[0] += SIZE_IMAGE;
	}
	else if (key == 'a')
	{
		if (content->map.map[y][x - 1] != '1')
			content->pos_player[0] -= SIZE_IMAGE;
	}
}

void	collect_collectibles(int y, int x, t_content *content)
{
	if (content->map.map[y][x] == 'C')
	{
		content->map.map[y][x] = '0';
		content->map.count++;
	}
}

int	put_textures(char key, t_content *content)
{
	const int	y = content->pos_player[1] / SIZE_IMAGE;
	const int	x = content->pos_player[0] / SIZE_IMAGE;

	content->pos_floor[0] = content->pos_player[0];
	content->pos_floor[1] = content->pos_player[1];
	move_and_wall_collision(key, y, x, content);
	if (content->pos_floor[1] != content->pos_player[1]
		|| content->pos_floor[0] != content->pos_player[0])
	{
		ft_printf("number of steps = %d\n", content->nbr_mvt);
		content->nbr_mvt++;
	}
	collect_collectibles(y, x, content);
	if (content->map.map[content->pos_player[1] / SIZE_IMAGE]
		[content->pos_player[0] / SIZE_IMAGE] == 'E'
		&& content->map.count == content->map.nbr_col)
		free_and_exit(content, 0);
	else if (content->map.map[y][x] == 'E')
		return (1);
	return (0);
}

int	key_press(int key, t_content *content)
{
	int		display_floor;

	display_floor = 0;
	if (key == KEY_W)
		display_floor = put_textures('w', content);
	else if (key == KEY_S)
		display_floor = put_textures('s', content);
	else if (key == KEY_D)
		display_floor = put_textures('d', content);
	else if (key == KEY_A)
		display_floor = put_textures('a', content);
	if (key == KEY_ESC)
		free_and_exit(content, 0);
	display_image(display_floor, content);
	return (0);
}

void	display_and_move_around(t_content *content)
{
	content->nbr_mvt = 0;
	mlx_key_hook(content->so_long.win, key_press, content);
}
