/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:40:50 by dsonmez           #+#    #+#             */
/*   Updated: 2025/02/23 21:54:26 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SOLONG_H
# define SOLONG_H

#include "./getnextline/get_next_line.h"
# include "../minilibx/mlx.h"

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	int			playercheck;
	int			exitcheck;
	size_t		size_x;
	int			size_y;
	t_player	player;
}				t_game;

typedef struct s_player
{
	int		x;
	int		y;
	int		move;

}			t_player;

char    **read_map();
int check_map(char **map);
int	check_elements(char **map, int *p, int *e, int *c);
int	check_walls(char **map, int width, int height);
int check_rectangle(char **map, int height, int width);
int	check_file(char *path,char *type);
int	ft_exit(t_game *game);
#endif
