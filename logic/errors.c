/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:57:17 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/21 16:19:30 by sbartoul         ###   ########.fr       */
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
		ft_printf("\nThis map is missing the walls\n");
		exit_window(game);
	}
}

void	check_errors(t_play *game)
{
	if_walls(game);
	character_valid(game);
}
