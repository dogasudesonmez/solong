/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_images_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 01:17:54 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/02 01:23:49 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	place_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player, width*30, width*30);
	game->x_axis = height;
	game->y_axis = width;
}

void	place_collectable(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win, game->collectable, width*30, width*30);
	game->x_axis = height;
	game->y_axis = width;
}

void	place_exit(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win, game->exit, width*30, width*30);
	game->x_axis = height;
	game->y_axis = width;
}

void	place_floor(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor, width*30, width*30);
	game->x_axis = height;
	game->y_axis = width;
}
void	place_wall(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win, game->wall, width*30, width*30);
	game->x_axis = height;
	game->y_axis = width;
}