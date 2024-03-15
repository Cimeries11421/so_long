#include "so_long.h"

void	find_pos_player(t_content *content)
{
	char	**tab;

	tab = content->map.map;
	content->map.y = 0;
	content->map.x = 0;
	while (tab[content->map.y])
	{
		while(tab[content->map.y][content->map.x])
		{
			if (tab[content->map.y][content->map.x] == 'P')
				return ;
			printf("tab[y][x] = %c\n", tab[y][x]);
			x++;
		}
		content->map.x = 0;
		y++;
	}
}

int		check_path(t_content *content)
{
		find_pos_player(content);
		
}
