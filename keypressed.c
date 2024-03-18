#include "mlx/mlx.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846264338327950288


#define KEY_ESCAPE 53

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

void	display_text(t_vars *vars, char *text)
{
	mlx_string_put(vars->mlx, vars->win, 50, 50, 0xFFFFFF, text);
}

int	close(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESCAPE)
		mlx_destroy_window(vars->mlx, vars->win);
	else
	{
		char message[80];
		sprintf(message, "Key with keycode %d pressed", keycode);
		display_text(vars, message);
	}
	return (0);
}

int	window_resize(t_vars *vars)
{
	printf("Window resized\n");
	return (0);
}

int	window_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	key_press_duration(t_vars *vars)
{
	printf("Key pressed for longer than 2 seconds\n");
	return (0);
}

int	mouse_enter(t_vars *vars)
{
	printf("Hello!\n");
	return (0);
}

int	mouse_leave(t_vars *vars)
{
	printf("Bye!\n");
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Key pressed: %d\n", keycode);
	return (0);
}

int	main()
{
	t_vars	vars;
	clock_t start_time;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 600, 500, "So long");
	// mlx_hook(vars.win, 6, 1L << 6, mouse_enter, &vars);
	// mlx_hook(vars.win, 7, 1L << 6, mouse_leave, &vars);

	// start_time = clock();
	// mlx_loop_hook(vars.mlx, key_press_duration, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_mouse_get_pos(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}