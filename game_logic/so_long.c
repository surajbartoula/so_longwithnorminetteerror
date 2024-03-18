/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:47:57 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/18 11:18:19 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *string, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)string;
	while (len--)
		*str++ = (unsigned char)c;
	return (string);
}

int	main(int argc, char	*argv[])
{
	t_play	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_play));
	map_reading(&game, argv);
	check_errors(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (game.width * 40),
			(game.height * 40), "so long");
	place_images_in_game(&game);
	adding_in_graphics(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx);
}
