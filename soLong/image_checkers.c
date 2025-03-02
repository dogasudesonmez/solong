/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:46:39 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/02 20:13:27 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_cp_checker(void)
{
	int	fd_player;
	int	fd_collectable;
	int	fd_exit;

	fd_player = open("images/player.xpm", O_RDWR);
	fd_collectable = open("images/collectable.xpm", O_RDWR);
	fd_exit = open("images/exit.xpm", O_RDWR);
	if (fd_player < 0 || fd_collectable < 0 || fd_exit < 0)
	{
		ft_printf("Error: Missing Image File\n");
		close(fd_player);
		close(fd_collectable);
		close(fd_exit);
		exit(1);
	}
	close(fd_player);
	close(fd_collectable);
	close(fd_exit);
}

void	ft_images_check(void)
{
	int	fd_floor;
	int	fd_wall;

	fd_floor = open("images/floor.xpm", O_RDWR);
	fd_wall = open("images/wall.xpm", O_RDWR);
	if (fd_floor < 0 || fd_wall < 0)
	{
		ft_printf("Error: Missing Image File\n");
		close(fd_floor);
		close(fd_wall);
		exit(1);
	}
	close(fd_floor);
	close(fd_wall);
	ft_cp_checker();
}