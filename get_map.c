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

static void	read_and_store_map(t_content *content, int fd)
{
	size_t	nbr_line;
	size_t	i;

	nbr_line = count_line(fd);
	close(fd);
	fd = open("map.ber", O_RDONLY);
	printf("nbr_line = %ld\n", nbr_line);
	content->map.map = malloc((nbr_line + 1) * sizeof (char*));
	i = 0;
	while(i < nbr_line)
	{
		content->map.map[i] = get_next_line(fd);
		printf("line = %s\n", content->map.map[i]);
		i++;
	}
	content->map.map[i] = NULL;
}

void	get_map(t_content *content)
{
	int		fd;

	fd = open("map.ber", O_RDONLY);
	read_and_store_map(content, fd);
//	if (!check_map)
		//free tab, exit ?;
}

