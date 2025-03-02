/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:40:50 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/02 20:12:57 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SOLONG_H
# define SOLONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

#include <fcntl.h>
#include "./libft/libft.h"
#include "./minilibx-linux/mlx.h"
#include "./printf/ft_printf.h"

typedef struct s_game
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		p_counter;
	int		c_counter;
	int		e_counter;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlx;
	void	*win;

}	t_game;


int	read_map(t_game *game, char **av);
int	ft_exit(t_game *game);
int check_map(t_game *game);
int	ft_charchecker(t_game *game);
int	check_elements(t_game *game, int height, int width);
int	check_height_walls(t_game *game);
int	check_width_walls(t_game *game);
void check_rectangle(t_game *game);
void	place_player(t_game *game, int height, int width);
void	place_collectable(t_game *game, int height, int width);
void	place_exit(t_game *game, int height, int width);
void	place_floor(t_game *game, int height, int width);
void	place_wall(t_game *game, int height, int width);
void place_images(t_game *game);
void place_graphs(t_game *game);
char	*get_next_line(int fd);

#endif