/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:13:30 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/21 08:35:03 by sbartoul         ###   ########.fr       */
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
	int	x_pos;
	int	y_pos;

	game->floor = mlx_xpm_file_to_image(game->mlx,
			"images/water.xpm", &x_pos, &y_pos);
	game->barrier = mlx_xpm_file_to_image(game->mlx,
			"images/tiles.xpm", &x_pos, &y_pos);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"images/dolphin.xpm", &x_pos, &y_pos);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"images/exit.xpm", &x_pos, &y_pos);
	game->collectable = mlx_xpm_file_to_image(game->mlx,
			"images/prey.xpm", &x_pos, &y_pos);
}

void	add_characters(t_play *game)
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
