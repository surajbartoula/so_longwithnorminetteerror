/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:17:59 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/18 19:37:31 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	right_move(t_play *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		ft_printf("\nYou have won, Congratulations!\n");
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

static int	keyboard_w_s(t_play *game, int keystroke)
{
	int	i;
	int	j;
	int	k;

	i = game->x;
	j = game->y;
	if (keystroke == 13 || keystroke == 126)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (keystroke == 1 || keystroke == 125)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	keyboard_a_d(t_play *game, int keystroke)
{
	int	i;
	int	j;
	int	k;

	i = game->x;
	j = game->y;
	if (keystroke == 0 || keystroke == 123)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (keystroke == 2 || keystroke == 124)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

int	key_hook(int keystroke, t_play *game)
{
	int	press;

	if (keystroke == 53)
		exit_window(game);
	if (keystroke == 13 || keystroke == 126)
		press = keyboard_w_s(game, keystroke);
	if (keystroke == 1 || keystroke == 125)
		press = keyboard_w_s(game, keystroke);
	if (keystroke == 0 || keystroke == 123)
		press = keyboard_a_d(game, keystroke);
	if (keystroke == 2 || keystroke == 124)
		press = keyboard_a_d(game, keystroke);
	if (press)
		adding_in_graphics(game);
	return (1);
}