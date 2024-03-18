/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:01:02 by ebriere           #+#    #+#             */
/*   Updated: 2024/03/17 20:01:04 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	destroy_images(t_content *content)
{
	if (content->textures.player != NULL)
		mlx_destroy_image(content->so_long.mlx, content->textures.player);
	if (content->textures.wall != NULL)
		mlx_destroy_image(content->so_long.mlx, content->textures.wall);
	if (content->textures.floor != NULL)
		mlx_destroy_image(content->so_long.mlx, content->textures.floor);
	if (content->textures.col != NULL)
		mlx_destroy_image(content->so_long.mlx, content->textures.col);
	if (content->textures.exit != NULL)
		mlx_destroy_image(content->so_long.mlx, content->textures.exit);
}

int	free_and_exit(t_content *content, int error)
{
	if (content->map.map != NULL)
		content->map.map = free_tab(content->map.map);
	destroy_images(content);
	if (content->so_long.win != NULL)
		mlx_destroy_window(content->so_long.mlx, content->so_long.win);
	if (content->so_long.mlx != NULL)
		mlx_destroy_display(content->so_long.mlx);
	free(content->so_long.mlx);
	if (error == 1)
		exit(-1);
	exit(0);
}

void	error_exit(t_content *content, char *str, int error)
{
	write(2, str, ft_strlen(str));
	free_and_exit(content, error);
}
