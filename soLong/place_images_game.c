/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_images_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 01:11:23 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/02 19:27:55 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void place_images(t_game *game)
{
    int i;
    int j;

    game->floor =  mlx_xpm_file_to_image(game->mlx, "images/floor.xpm", &i, &j);
    game->wall =  mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &i, &j);
    game->player = mlx_xpm_file_to_image(game->mlx, "images/player.xpm", &i, &j);
    game->exit = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &i, &j);
    game->collectable = mlx_xpm_file_to_image(game->mlx, "images/collectable.xpm", &i, &j);
}
void place_graphs(t_game *game)
{
    int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				place_wall(game, height, width);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				place_exit(game, height, width);
			if (game->map[height][width] == '0')
				place_floor(game, height, width);
			width++;
		}
		height++;
	}
}