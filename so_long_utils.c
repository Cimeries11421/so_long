#include "libft.h"
	
char	**free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

void	error_exit(t_content *content, char *str)
{
}

void	free_and_exit(t_content)
{
	if (content->map.map != NULL)
		content->map.map = free_tab(content->map.map);
	if (content->mlx != NULL)
		mlx_destroy_window(content->so_long.mlx, so_long.win); //apres la loop pour tour free.
		mlx_destroy_display(content->so_long.mlx);

	if (content->mlx != NULL)
	if (content->mlx != NULL)

}
