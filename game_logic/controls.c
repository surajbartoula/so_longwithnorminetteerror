/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:17:59 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/19 11:13:14 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_w(t_play *game, int keystroke)
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
		k = character_steps(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	ft_printf("Steps Taken: %d\n", game->counter);
	ft_printf("Collectables Left: %d\n", game->collectables);
	return (1);
}

static int	key_s(t_play *game, int keystroke)
{
	int	i;
	int	j;
	int	k;

	i = game->x;
	j = game->y;
	if (keystroke == 1 || keystroke == 125)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = character_steps(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	ft_printf("Steps Taken: %d\n", game->counter);
	ft_printf("Collectables Left: %d\n", game->collectables);
	return (1);
}

static int	key_a(t_play *game, int keystroke)
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
		k = character_steps(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	ft_printf("Steps Taken: %d\n", game->counter);
	ft_printf("Collectables Left: %d\n", game->collectables);
	return (1);
}

static int	key_d(t_play *game, int keystroke)
{
	int	i;
	int	j;
	int	k;

	i = game->x;
	j = game->y;
	if (keystroke == 2 || keystroke == 124)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = character_steps(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	ft_printf("Steps Taken: %d\n", game->counter);
	ft_printf("Collectables Left: %d\n", game->collectables);
	return (1);
}

int	key_hook(int keystroke, t_play *game)
{
	int	press;

	if (keystroke == 53)
		exit_window(game);
	if (keystroke == 13 || keystroke == 126)
		press = key_w(game, keystroke);
	if (keystroke == 1 || keystroke == 125)
		press = key_s(game, keystroke);
	if (keystroke == 0 || keystroke == 123)
		press = key_a(game, keystroke);
	if (keystroke == 2 || keystroke == 124)
		press = key_d(game, keystroke);
	if (press)
		add_characters(game);
	return (0);
}
