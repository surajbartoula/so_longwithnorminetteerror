/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:25:22 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/20 21:14:41 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "../mlx/mlx.h"

typedef struct t_type
{
	int		fd;
	int		height;
	int		width;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x;
	int		y;
	int		counter;
	int		collectables;

	char	**map;
	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlx;
	void	*win;
}	t_play;

int			exit_window(t_play *game);
int			character_steps(t_play *game, int i, int j);
int			key_hook(int keystroke, t_play *game);
int			read_map_ber(t_play *game, char *argv[]);
void		check_errors(t_play *game);
void		character_valid(t_play *game);
void		add_characters(t_play *game);
void		place_images_in_game(t_play *game);

#endif