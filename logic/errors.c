/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:57:17 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/27 22:55:13 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	horizontalwall(t_play *game)
{
	int	width;
	int	w;

	width = game->width;
	w = 0;
	while (w < width)
	{
		if (game->map[0][w] != '1'
			|| game->map[game->height - 1][w] != '1')
			return (0);
		w++;
	}
	return (1);
}

static int	verticalwall(t_play *game)
{
	int	height;
	int	h;

	h = 0;
	height = game->height;
	while (h < height)
	{
		if (game->map[h][0] != '1'
			|| game->map[h][game->width - 1] != '1')
			return (0);
		h++;
	}
	return (1);
}

static void	if_walls(t_play *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		ft_printf("Error\nThis map is missing the walls or there is gap.\n");
		exit_window(game);
	}
}

static void	if_rectangular(t_play *game)
{
	int	h;
	int	w;
	int	i;
	int	wsize;

	h = game->height;
	w = game->width;
	i = 1;
	while (i < h)
	{
		wsize = (int)ft_maplen(game->map[i]);
		if (wsize != w)
		{
			ft_printf("Error\nThe map provided is not rectangular.\n");
			exit_window(game);
		}
		i++;
	}
}

void	check_errors(t_play *game)
{
	if_walls(game);
	if_rectangular(game);
	character_valid(game);
	able_to_finish_game(game);
}
