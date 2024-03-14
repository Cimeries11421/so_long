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
	size_t y;
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
	//check_char
	//check_clone
	//check_path
}
