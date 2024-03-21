/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:57:17 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/17 23:00:52 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	horizontalwall(t_play *game)
{
	int	i;
	int	j;

	i = game->width;
	j = 0;
	while (j < i)
	{
		if (game->map[0][i] == '1' && game->map[game->height - 1][j] == '1')
			return (0);
		j++;
	}
	return (1);
}

static int	verticalwall(t_play *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->width;
	while (height < game->height)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width - 1] == '1'))
			return (0);
		height++;
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
