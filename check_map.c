/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:54:24 by dsonmez           #+#    #+#             */
/*   Updated: 2025/02/09 21:41:42 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "./libft/libft.h"
#include "./printf/ft_printf.h"

int check_rectangle(char **map, int height, int width)
{
    while(height > 0)
    {
        if (width != ft_strlen(map[height]))
		{
			ft_printf("Harita Dikdörtgen değil");
			return (0);
		}    
	}
	return (1);
}

int	check_walls(char **map, int width, int height)
{
	while (map[width] != NULL)
	{
		width++;
		height = 0;
		while (map[width][height] != NULL)
		{
			height++;
		}
		height--;
		if(map[width][height] == '1')
			return (1);
	}
	return (0);
}
int	check_elements(char **map, int *p, int *e, int *c)
{
	while(*map != NULL)
    {
        if ((map[i][j] != '1') && (map[i][j] == '0'))
			ft_printf("Harita geçersiz");
		if (map[i][j] == 'E')
			*e++;
		if (map[i][j] == 'P')
			*p++;
		if (map[i][j] == 'C')
			*c++;
    }
}

int check_map(char **map)
{
	int i;
	int p;
	int	e;
	int	c;
	int width;
	int height;

	width = ft_strlen(map[0]);
	i = 0;
	p = 0;
	e = 0;
	c = 0;
	height = 0;
	while(map[i++] != NULL)
		height++;
	if (!check_rectangle(map,height,width))
		return (0);
	if (!check_walls(map,width,height))
		return (0);
	if (!check_elements(map, &p, &e, &c))
		return (0);
	ft_printf("Harita geçerlidir. \n");
}
