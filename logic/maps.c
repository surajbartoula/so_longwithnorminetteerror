/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:43:41 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/28 00:28:38 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_play *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->height++;
	temp = malloc(sizeof(char *) * (game->height + 1));
	temp[game->height] = NULL;
	while (i < game->height - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	read_map_ber(t_play *game, char *argv[])
{
	char	*readmap;
	int		count;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		ft_printf("Error\nNot able to open the file.\n");
		return (0);
	}
	count = 0;
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (readmap == NULL && count == 0)
		{
			ft_printf("Error\nFile is empty.\n");
			return (0);
		}
		if (!add_line(game, readmap))
			break ;
		count++;
	}
	close (game->fd);
	game->width = width_of_map(game->map[0]);
	return (1);
}
