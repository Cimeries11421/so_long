/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:00:29 by ebriere           #+#    #+#             */
/*   Updated: 2024/03/17 22:00:32 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

# define KEY_W 119
# define KEY_S 115
# define KEY_D 100
# define KEY_A 97
# define KEY_ESC 65307
# define Y_W 1080
# define SIZE_IMAGE 158

typedef struct s_objects
{
	int		p;
	int		c;
	int		e;
}			t_objects;

typedef struct s_struct
{
	void		*mlx;
	void		*win;
}			t_solong;

typedef struct s_map
{
	char	**map;
	int		nbr_col;
	int		count;
	size_t	size_y;
	size_t	size_x;
	size_t	y;
	size_t	x;
}				t_map;

typedef struct s_textures
{
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*col;
	char	*path_player;
	char	*path_floor;
	char	*path_wall;
	char	*path_exit;
	char	*path_col;
	int		width;
	int		height;
}				t_textures;

typedef struct s_content
{
	int			pos_player[2];
	int			pos_floor[2];
	int			nbr_mvt;
	t_solong	so_long;
	t_textures	textures;		
	t_map		map;
}				t_content;

void	get_map(t_content *content, char **av);
void	check_map(t_content *content);
int		check_path(t_content *content);
int		key_press(int key, t_content *content);
void	store_textures(t_content *content);
void	display_image(int display_exit, t_content *content);
void	display_and_move_around(t_content *content);
void	error_exit(t_content *content, char *str, int error);
int		free_and_exit(t_content *content, int error);
char	**free_tab(char **tab);

#endif
