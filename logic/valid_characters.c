/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:27:09 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/26 15:08:56 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_map_error(char *error_msg, t_play *game)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error_msg);
	exit_window(game);
}

static void	count_checker(t_play *game, int height, int width)
{
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
		game->columncount++;
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
