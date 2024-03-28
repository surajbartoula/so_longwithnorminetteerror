/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:27:09 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/28 09:44:44 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_error(char *error_msg, t_play *game)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error_msg);
	exit_window(game);
}

int	sorounded_by_wall(t_play *game, int i, int j)
{
	if ((game->map[i - 1][j] == '1' || game->map[i - 1][j] == 'E')
		&& (game->map[i + 1][j] == '1' || game->map[i + 1][j] == 'E')
		&& (game->map[i][j - 1] == '1' || game->map[i][j - 1] == 'E')
		&& (game->map[i][j + 1] == '1' || game->map[i][j + 1] == 'E'))
		return (1);
	return (0);
}

static void	count_checker(t_play *game, int height, int width)
{
	char	**visited;

	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		ft_printf("Error Here\nWrong character %c\n", game->map[height][width]);
		exit_window(game);
	}
	if (game->map[height][width] == 'C')
	{
		game->columncount++;
		visited = visited_space(game->height, game->width);
		if (collect_collectibles(game, height, width, visited) == 0)
			ft_map_error("The collectible is sorrounded by wall.", game);
		free_visited(visited, game->height);
	}
	if (game->map[height][width] == 'P')
		game->playercount++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
}

void	character_valid(t_play *game)
{
	int	height;
	int	width;

	height = 1;
	while (height < game->height - 1)
	{
		width = 1;
		while (width < game->width - 1)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (game->playercount != 1)
		ft_map_error("Player should be only one.", game);
	else if (game->exitcount != 1)
		ft_map_error("Exit should be only one.", game);
	else if (game->columncount < 1)
		ft_map_error("Collectable should be alteast one.", game);
}
