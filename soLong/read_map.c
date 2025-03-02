/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:37:44 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/02 20:50:37 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	width_of_map(char *string)
{
	int	width;

	width = 0;
	if (!string)
    	return (0);
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

int	add_line(t_game *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!temporary)
	{
    	ft_printf("Error: Memory allocation failed\n");
    	return (0);
	}
	temporary[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	read_map(t_game *game, char **av)
{
	char	*readmap;
	int		i;

	i = 0;
	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (i == 0 && !readmap)
		{
			ft_printf("Error: Empty Map\n");
			free(game->map);
			ft_exit(game);
		}
		else
			i++;
		if (!add_line(game, readmap))
			break ;
	}
	close (game->fd);
	game->widthmap = width_of_map(game->map[0]);
	if (!game->map || !game->map[0])
	{
    	ft_printf("Error: Invalid Map\n");
    	ft_exit(game);
	}
	check_rectangle(game);
	return (1);
}