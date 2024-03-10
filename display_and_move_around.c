#include "so_long.h"

static int	key_press(int key, t_content *content)
{
	if (key == 119)
		content->pos_player[0]++;
	else if (key == 115)
		content->pos_player[0]--;
	else if (key == 100)
		content->pos_player[1]++;
	else if (key == 97)
		content->pos_player[1]--;
	printf("player[0] = %d player[1] = %d\n", content->pos_player[0], content->pos_player[1]);
	return (0);
}

/*void static	display_image(t_solong *content->so_long, t_content->textures *textures, 
	t_content *content)
{
	mlx_put_image_to_window(content->so_long->mlx, so_long->win, content->textures->col, 145, 145);
	mlx_put_image_to_window(content->so_long->mlx, so_long->win, content->textures->floor, 80, 80);
	mlx_put_image_to_window(content->so_long->mlx, so_long->win, content->textures->wall, 210, 210);
	mlx_put_image_to_window(content->so_long->mlx, so_long->win, content->textures->exit, 300, 300);
}*/

int	display_image(t_content	*content)
{
	mlx_put_image_to_window(content->so_long->mlx, so_long->win, content->textures->player, 
			content->pos_player[0], content->pos_player[1]);
}

void	display_and_move_around(t_content *content)
{
	mlx_key_hook(content.so_long.win, key_press, &content);
	mlx_loop_hook(content.so_long.mlx, display_image, &content);
}
