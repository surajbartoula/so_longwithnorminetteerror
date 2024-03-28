/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visited.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:02:34 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/28 10:04:13 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**visited_space(int height, int width)
{
	int		i;
	char	**visited;

	visited = malloc(sizeof(char *) * height);
	if (!visited)
		return (0);
	i = 0;
	while (i < height)
	{
		visited[i] = malloc(sizeof(char) * (width + 1));
		memset(visited[i], 0, (width + 1) * sizeof(char));
		i++;
	}
	return (visited);
}

void	free_visited(char **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(visited[i++]);
	free(visited);
}
