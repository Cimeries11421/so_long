#include "so_long.h"

static int	check_dimension(t_content *content)
{
	size_t	y;
	size_t	len;

	y = 0;
	len = ft_strlen(content->map.map[y]);
	while (content->map.map[y])
	{
		if (len != ft_strlen(content->map.map[y]))
			return (-1);
		y++;
	}
	return (0);
}

static int	check_wall(t_content *content)
{
	size_t	y;
	size_t	x;
	size_t	end;
	size_t	end_line;

	y = 0;
	x = 0;
	end = 0;
	while (content->map.map[end + 1])
		end++;
	while (content->map.map[y][x]) 
	{
		if (content->map.map[y][x] != '1' || content->map.map[end][x] != '1' )
			return (-1);
		x++;
	}
	end_line = ft_strlen(content->map.map[y]) - 1;
	while (content->map.map[y]) 
	{	
		if (content->map.map[y][0] != '1' || content->map.map[y][end_line] != '1')
			return (-1);
		y++;
	}
	return (0);	
}

static int	check_nbr_objects(t_content *content)
{
	size_t		y;
	size_t		x;
	t_objects	object;

	y = 0;
	x = 0;
	object = (t_objects){0};
	while (content->map.map[y])
	{
		while (content->map.map[y][x])
		{
			if (content->map.map[y][x] == 'P')
				object.P++;
			if (content->map.map[y][x] == 'C')
				object.C++;
			if (content->map.map[y][x] == 'E')
				object.E++;
			x++;
		}
		x = 0;
		y++;
	}
	if (object.P != 1 || object.C < 1 || object.E != 1)
		return (-1);
	return (0);
}

static int	check_char(t_content *content)
{
	size_t		y;
	size_t		x;
	char		**tab;

	y = 0;
	x = 0;
	tab = content->map.map;
	while (tab[y])
	{
		while (tab[y][x])
		{
			if (tab[y][x] != '1' && tab[y][x] != '0' && tab[y][x] != 'P' && tab[y][x] != 'C' 
					&& tab[y][x] != 'E')
				return (-1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	check_map(t_content *content)
{
	if (check_dimension(content) != 0)
	{
		write(2, "Error : map got wrong dimension\n", 33);
		//free_tab + message d'erreur
		exit(-1);
	}
	if (check_wall(content) != 0)
	{
		write(2, "Error : map got bad walls\n", 26);
		exit(-1);
	}
	if (check_nbr_objects(content) != 0)
	{	
		write(2, "Error : wrong number of objects\n", 33);
		exit(-1);
	}
	if (check_char(content) != 0)
	{
		write(2, "Error : map got wrong characters\n", 34);
		exit(-1);
	}
	if (check_path(content) != 0)
	{
		write(2, "Error : There is no path to complete the game\n", 52);
		exit(-1);
	}
}
