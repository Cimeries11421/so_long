/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:00:43 by ebriere           #+#    #+#             */
/*   Updated: 2024/03/18 22:50:56 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (content->map.map[y][0] != '1' ||
				content->map.map[y][end_line] != '1')
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
				object.p++;
			if (content->map.map[y][x] == 'C')
				object.c++;
			if (content->map.map[y][x] == 'E')
				object.e++;
			x++;
		}
		x = 0;
		y++;
	}
	if (object.p != 1 || object.c < 1 || object.e != 1)
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
			if (tab[y][x] != '1' && tab[y][x] != '0' && tab[y][x] != 'P'
					&& tab[y][x] != 'C' && tab[y][x] != 'E')
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
		error_exit(content, "Error : map got wrong dimension\n", 1);
	if (check_wall(content) != 0)
		error_exit(content, "Error : map got bad walls\n", 1);
	if (check_nbr_objects(content) != 0)
		error_exit(content, "Error : map got wrong number of objects\n", 1);
	if (check_char(content) != 0)
		error_exit(content, "Error : map got wrong characters\n", 1);
	if (check_path(content) != 0)
		error_exit(content, "Error : no path to complete the game\n", 1);
}
