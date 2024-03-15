#include "so_long.h"



static void	display_image(int display_exit, t_content	*content)
{
	if (display_exit == 1)
	{
		mlx_put_image_to_window(content->so_long.mlx, content->so_long.win, 
			content->textures.exit, content->pos_floor[0], content->pos_floor[1]);
	}
	else
		mlx_put_image_to_window(content->so_long.mlx, content->so_long.win,
			content->textures.floor, content->pos_floor[0] , content->pos_floor[1]);

	mlx_put_image_to_window(content->so_long.mlx, content->so_long.win, content->textures.player, 
			content->pos_player[0], content->pos_player[1]);
}

void	move_and_create_wall_collision(char key, int y, int x, t_content *content)
{
	if (key == 'w')
	{
		if (content->map.map[y - 1][x] != '1')
			content->pos_player[1]-= 32;
	}
	else if (key == 's')
	{
		if (content->map.map[y + 1][x] != '1')
			content->pos_player[1] += 32;
	}
	else if (key == 'd')
	{
		if (content->map.map[y][x + 1] != '1')
			content->pos_player[0]+= 32;
	}
	else if (key == 'a')
	{
		if (content->map.map[y][x - 1] != '1')
			content->pos_player[0]-= 32;
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

int		put_textures(char key, t_content *content )
{
	const int	y = content->pos_player[1] / 32; 
	const int	x = content->pos_player[0] / 32;
	
	content->pos_floor[0] = content->pos_player[0];
	content->pos_floor[1] = content->pos_player[1];
	content->nbr_mvt++;
	write(2, "number of steps = ", 18);
	ft_putnbr_fd(content->nbr_mvt, 2);
	write(2, "\n", 1);
	//write(2, ft_atoi(content->nbr_mvt), ft_strlen(ft_atoi(content->nbr_mvt)));
	move_and_create_wall_collision(key, y, x, content);
	collect_collectibles(y, x, content);
	if (content->map.map[content->pos_player[1] / 32][content->pos_player[0] / 32] == 'E'
			&& content->map.count == content->map.nbr_col)
		exit(0);
	else if (content->map.map[y][x] == 'E')
		return(1);
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
		exit(0);// free all, destroy and exit;
	display_image(display_floor, content);
	return (0);
}

int		mouse_hook(int hook, t_content *content)
{
	if (hook == 1)
		printf("Pigeon\n");
}

void	display_and_move_around(t_content *content)
{
	content->nbr_mvt = 0;
	mlx_key_hook(content->so_long.win, key_press, content);
	mlx_mouse_hook(content->so_long.win, mouse_hook, content);

	//mlx_loop_hook(content->so_long.mlx, display_image, content);
}
