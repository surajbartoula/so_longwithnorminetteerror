/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   able_to_finish.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:33:12 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/28 10:45:24 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	finish_game(t_play *game, int i, int j, char **visited)
{
	if (game->map[i][j] == 'E')
		return (1);
	visited[i][j] = 1;
	if (i > 0 && game->map[i - 1][j] != '1' && !visited[i - 1][j])
		if (finish_game(game, i - 1, j, visited))
			return (1);
	if (i < game->height - 1 && game->map[i + 1][j] != '1'
		&& !visited[i + 1][j])
		if (finish_game(game, i + 1, j, visited))
			return (1);
	if (j > 0 && game->map[i][j - 1] != '1' && !visited[i][j - 1])
		if (finish_game(game, i, j - 1, visited))
			return (1);
	if (j < game->width - 1 && game->map[i][j + 1] != '1' && !visited[i][j + 1])
		if (finish_game(game, i, j + 1, visited))
			return (1);
	return (0);
}

void	visited_checked(t_play *game, int h, int w)
{
	char	**visited;

	visited = visited_space(game->height, game->width);
	if (finish_game(game, h, w, visited) == 0)
		ft_map_error("Provided map blocks the player from exiting.", game);
	free_visited(visited, game->height);
}

void	able_to_finish_game(t_play *game)
{
	int		height;
	int		width;
	int		foundplayer;

	height = 0;
	foundplayer = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			if (game->map[height][width] == 'P')
			{
				foundplayer = 1;
				break ;
			}
			width++;
		}
		if (foundplayer == 1)
			break ;
		height++;
	}
	visited_checked(game, height, width);
}
