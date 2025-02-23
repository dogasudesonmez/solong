/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:32:56 by dsonmez           #+#    #+#             */
/*   Updated: 2025/02/23 21:57:36 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "solong.h"

#define ESC_KEY 65307

void *wall_img;
int img_width, img_height;

void	message(char *msg, t_game *game)
{
	printf("%s", msg);
	map_destroy(game);
	exit(0);
}
// dosya uzantısı ve harita kontrollerine giden fonksiyon --kontroller check mapte
int	map_controller(char **map, char *path,char *type)
{
	check_file(path, type);
	check_map(map);
}
void	start(t_game *game)
{
	game->exitcheck = 0;
}
int main(int ac, char *av)
{
	int	tile_size;
	t_game	game;
	int	y;
	int x;
	x = 0;
	y = 0;
	tile_size = 64;
	char **map;
	if (av != 2)
		message("Sadece 2 arguman girebilirsin\n", &game);
	map = read_map(av[2]);
	map_controller(map, av[2],"ber");
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.size_x, game.size_y, "SO LONG OYUN");
	if(!(game.mlx))
		return (1);
	// x ya basınca oyun kapanmalı
	mlx_key_hook(game.window, ft_exit, &game);
	wall_img = mlx_xpm_file_to_image(game.mlx, "wall.xpm", &img_width, &img_height);
	if (!wall_img)
	{
		printf("Hata: XPM dosyası yüklenemedi!\n");
		return (1);
	}

	while (map[y] != NULL)
    {
        while (map[y][x] != '\0')
        {
            if (map[y][x] == '1')
            {
                mlx_put_image_to_window(game.mlx, game.window, wall_img, x * tile_size, y * tile_size);
            }
			x++;
        }
		y++;
    }
	mlx_loop(mlx);
    return (0);
}
