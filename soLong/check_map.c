/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:54:24 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/02 21:07:05 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void check_rectangle(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->heightmap - 1)
	{
		if ((int)(ft_strlen(game->map[i])) - 1 != game->widthmap)
		{
			ft_printf("Error: Not Rectangular\n");
			ft_exit(game);
		}
		i++;
	}
	if ((int)(ft_strlen(game->map[i])) - 1 != game->widthmap)
	{
		if (game->map[i][game->widthmap] != '\0')
		{
			ft_printf("Error: Not Rectangular\n");
			ft_exit(game);
		}
	}
}

int	check_width_walls(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}


int	check_height_walls(t_game *game)
{
	int	height;
	int	width;

	height = game->heightmap;
	width = 0;
	while (width < game->widthmap)
	{
		if (!(game->map[0][width] == '1'
			&& game->map[height - 1][width] == '1'))
			return (0);
		width++;
	}
	return (1);
}

int	check_elements(t_game *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		ft_printf("Error Here!%c\n", game->map[height][width]);
		return (0);
	}
	if (game->map[height][width] == 'C')
		game->c_counter++;
	if (game->map[height][width] == 'P')
		game->p_counter++;
	if (game->map[height][width] == 'E')
		game->e_counter++;
	return (1);
}


int	ft_charchecker(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			check_elements(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->p_counter == 1 && game->c_counter >= 1
			&& game->e_counter == 1))
	{
		ft_printf("Error: Player, collectable or exit issue\n");
		return (0);
	}
	return (1);
}

//path kontrol eksik
int check_map(t_game *game)
{	
	if (!check_width_walls(game))
		return (0);
	if (!check_height_walls(game))
		return (0);
	if (!check_elements(game, game->heightmap, game->widthmap))
		return (0);
	if (!ft_charchecker(game))
		return (0);
	ft_printf("Harita geçerlidir. \n");
	return (1);
}
