/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:47:57 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/26 15:11:46 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	argumenterror(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("Error\nUsage: './so_long mappath/mapname.ber'\n");
		return (0);
	}
	if (argv[1] == NULL)
	{
		ft_printf("Error\n");
		ft_printf("No file given.\n");
		return (0);
	}
	if (!has_ber_extension(argv[1]))
	{
		ft_printf("Error\n");
		ft_printf("Please provide the right extension with .ber.\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char	*argv[])
{
	t_play	game;

	if (argumenterror(argc, argv) == 0)
		return (0);
	ft_memset(&game, 0, sizeof(t_play));
	if (read_map_ber(&game, argv) == 0)
		return (0);
	check_errors(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (game.width * 40),
			(game.height * 40), "so long");
	place_images_in_game(&game);
	add_characters(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx);
}
