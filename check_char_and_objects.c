#include "so_long.h"

/*void	display_tab(char **tab)
{
	size_t	i;

	i = 0;
	while(tab[i])
	{
		printf("line : %s\n", tab[i]);
		i++;
	}
}*/

char	**clone_map(t_content *content)
{
	char	**tab;
	size_t	len;
	size_t	y;

	len = 0;
	y = 0;
	dprintf(2, "sejgoreigje\n");
	while (content->map.map[y])
	{
		y++;
		len++;
	}
	y = 0;

	tab = malloc((len + 1) * sizeof(char *));
	while (content->map.map[y])
	{
	
		tab[y] = ft_strdup(content->map.map[y]);
		y++;
	
	}
	tab[y] = NULL;
	return (tab);
}

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
		content->map.x++;
		}
		content->map.x = 0;
		content->map.y++;
	}
}

void	flood_fill(char **tab, size_t y, size_t x)
{
	if (tab[y][x] == '1' || tab[y][x] == 'X')
		return ;
	write(2, "\n", 1);
	tab[y][x] = 'X';
	flood_fill(tab, y - 1, x);	
	flood_fill(tab, y + 1, x);
	flood_fill(tab, y, x - 1);
	flood_fill(tab, y, x + 1);
	return ;
}

int		path(char **tab)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	while (tab[y])
	{
		while (tab[y][x])
		{
			if (tab[y][x] == 'C' || tab == 'E')
				return (-1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int		check_path(t_content *content)
{
	char	**tab_tmp;

	tab_tmp = clone_map(content);
	find_pos_player(content);
	printf("tab[%ld][%ld] = %c\n", content->map.y, content->map.x,
	content->map.map[content->map.y][content->map.x]);
	flood_fill(tab_tmp, content->map.y, content->map.x);
	if (path(tab_tmp) != 0)
		return (-1);
	return (0);
}
