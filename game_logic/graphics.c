/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:13:30 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/18 16:51:55 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MPIW mlx_put_image_to_window

static void	place_player(t_play *game, int height, int width)
{
	MPIW(game->mlx, game->win, game->player, width * 40, height * 40);
	game->y = height;
	game->x = width;
}

static void	place_collectable(t_play *game, int height, int width)
{
	MPIW(game->mlx, game->win, game->collectable, width * 40, height * 40);
	game->collectables++;
}

void	place_images_in_game(t_play *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx,
			"game_images/water.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlx,
			"game_images/tiles.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"game_images/dolphin.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"game_images/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlx,
			"game_images/prey.xpm", &i, &j);
}

void	adding_in_graphics(t_play *game)
{
	int	h;
	int	w;

	game->collectables = 0;
	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == '1')
				MPIW(game->mlx, game->win, game->barrier, w * 40, h * 40);
			if (game->map[h][w] == 'C')
				place_collectable(game, h, w);
			if (game->map[h][w] == 'P')
				place_player(game, h, w);
			if (game->map[h][w] == 'E')
				MPIW(game->mlx, game->win, game->exit, w * 40, h * 40);
			if (game->map[h][w] == '0')
				MPIW(game->mlx, game->win, game->floor, w * 40, h * 40);
			w++;
		}
		h++;
	}
}
