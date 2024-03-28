/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   able_to_collect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:35:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/28 10:49:13 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collect_collectibles(t_play *game, int i, int j, char **visited)
{
	if (game->map[i][j] == 'P')
		return (1);
	visited[i][j] = 1;
	if (i > 0 && game->map[i - 1][j] != '1' && game->map[i - 1][j] != 'E'
		&& !visited[i - 1][j])
		if (collect_collectibles(game, i - 1, j, visited))
			return (1);
	if (i < game->height - 1 && game->map[i + 1][j] != '1'
		&& game->map[i + 1][j] != 'E' && !visited[i + 1][j])
		if (collect_collectibles(game, i + 1, j, visited))
			return (1);
	if (j > 0 && game->map[i][j - 1] != '1' && game->map[i][j - 1] != 'E'
		&& !visited[i][j - 1])
		if (collect_collectibles(game, i, j - 1, visited))
			return (1);
	if (j < game->width - 1 && game->map[i][j + 1] != '1'
		&& game->map[i][j + 1] != 'E' && !visited[i][j + 1])
		if (collect_collectibles(game, i, j + 1, visited))
			return (1);
	return (0);
}
