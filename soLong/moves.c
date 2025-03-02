/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 02:29:10 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/02 20:13:44 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


int	right_move(t_game *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		game->counter++;
		ft_printf("Steps Taken: %i\n", game->counter);
		ft_printf("\nYou Have Won, Congrats!\n");
		ft_exit(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

int	key_w_s(t_game *game, int movement)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 13)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (movement == 1)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j - 1][i] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->counter);
	return (1);
}

int	key_a_d(t_game *game, int movement)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 0)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (movement == 2)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j][i - 1] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->counter);
	return (1);
}

int	controls_manager(int keycode, t_game *game)
{
	int	works;

	works = 0;
	if (keycode == 53)
		ft_exit(game);
	else if (keycode == 1 || keycode == 13)
		works = key_w_s(game, keycode);
	else if (keycode == 0 || keycode == 2)
		works = key_a_d(game, keycode);
	if (works)
		place_graphs(game);
	return (1);
}