/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:12:20 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/19 11:13:22 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	character_steps(t_play *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		ft_printf("\nCongratulations you have won!\n");
		exit_window(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x = i;
		game->y = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x = i;
		game->y = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}
