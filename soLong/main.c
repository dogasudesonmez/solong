/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:03:05 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/02 21:08:15 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdlib.h>

int	ft_exit(t_game *game)
{
	int	line;

	line = 0;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	while (line < game->heightmap)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}
int main(int ac, char **av)
{
	t_game game;
	if (ac == 2)
	{
		ft_memset(&game, 0, sizeof(t_game));
		read_map(&game, av);
		check_map(&game);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, (game.widthmap * 40), (game.heightmap * 40), "so_long");
		place_images(&game);
		place_graphs(&game);
		mlx_loop(game.mlx);
	}
	return (0);
}