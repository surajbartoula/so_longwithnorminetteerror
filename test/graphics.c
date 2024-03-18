#include "mlx/mlx.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		color;
	int		pos;
}			t_data;

void	render_rainbow(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < 480)
	{
		x = 0;
		while (x < 640)
		{
			color = (data->color + x + y) % 0xFFFFFF;
			mlx_pixel_put(data->mlx, data->win, x, y, color);
			x++;
		}
		y++;
	}
	data->color += 20;
	if (data->color >= 0xFFFFFF)
		data->color = 0;
}

int	key_hook(int keycode, t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
	}
	return (0);
}

int	main( void )
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 600, 500, "Moving Rainbow");
	data.color = 0;
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop_hook(data.mlx, (void *)render_rainbow, &data);
	mlx_loop(data.mlx);
}
