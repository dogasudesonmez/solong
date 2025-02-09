/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:37:44 by dsonmez           #+#    #+#             */
/*   Updated: 2025/02/09 19:57:10 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <fcntl.h>
#include <stdlib.h>

int	read_map()
{
	int	fd;
	char *line;
	char **map;
	int	i;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	map = malloc(sizeof(char)*100);
	if (map == NULL)
		return (NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i] = line;
		i++; 
	}
	map[i] = NULL;
	close(fd);
    return (map);
}