/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:41:47 by dsonmez           #+#    #+#             */
/*   Updated: 2025/02/23 21:58:20 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_exit(game);
	else if (keycode == W || keycode == UARROW)
		ft_move(game, 'y', UP);
	else if (keycode == A || keycode == LARROW)
		ft_move(game, 'x', LEFT);
	else if (keycode == S || keycode == DARROW)
		ft_move(game, 'y', DOWN);
	else if (keycode == D || keycode == RARROW)
		ft_move(game, 'x', RIGHT);
	return (0);
}