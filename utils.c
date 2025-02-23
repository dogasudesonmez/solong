/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:42:46 by dsonmez           #+#    #+#             */
/*   Updated: 2025/02/23 21:53:13 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "./minilibx/mlx.h"

int	ft_exit(t_game *game)
{
    free(game);
    mlx_destroy_window(game->mlx, game->window);
    return (0);
}
