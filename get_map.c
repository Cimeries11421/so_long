#include "so_long.h"

static size_t	count_line(int fd)
{
	size_t	nbr_line;
	char	*line;

	nbr_line = 0;
	line = "begin";
	while(line)
	{
		line = get_next_line(fd);
//		printf("%s", line);
		nbr_line++;
	}
	return (nbr_line - 1); //-1 pour le null
}

static void	read_and_store_map(t_content *content, int fd, char **av)
{
	size_t	nbr_line;
	size_t	i;

	nbr_line = count_line(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	printf("nbr_line = %ld\n", nbr_line);
	content->map.map = malloc((nbr_line + 1) * sizeof (char*));
	i = 0;
	while(i < nbr_line)
	{
		content->map.map[i] = get_next_line(fd);
		printf("line = %s", content->map.map[i]);
		i++;
	}
	content->map.map[i] = NULL;
	close(fd); //proteger close ? 
}

static void	replace_endline_by_0(t_content *content)
{
	size_t	y;
	char	*p;

	y = 0;
	while(content->map.map[y])
	{
		p = ft_strchr(content->map.map[y], '\n');
		if(p)
			*p = '\0';
		y++;
	}
}

void	get_map(t_content *content, char **av)
{
	int		fd;
	
	fd = open(av[1], O_RDONLY);
	read_and_store_map(content, fd, av);
	replace_endline_by_0(content);
//	display_tab(content);
	check_map(content);
	content->map.size_y = 0;
	content->map.size_x = ft_strlen(content->map.map[content->map.size_y]) * 32;
	while(content->map.map[content->map.size_y])
		content->map.size_y++;
	content->map.size_y *= 32;

//	if (!check_map)
		//free tab, exit ?;
}

