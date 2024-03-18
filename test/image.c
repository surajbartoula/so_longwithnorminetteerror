#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

// typedef struct s_vars {
// 	void	*mlx;
// 	void	*win;
// 	void	*img;
// }	t_vars;

// int	main( void )
// {
// 	t_vars	vars;
// 	char	*relative_path = "./test.xpm";
// 	int		img_width;
// 	int		img_height;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 600, 500, "So Long");
// 	vars.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
// 	mlx_loop(vars.mlx);
// }


#define NUM_FRAMES 4
#define FRAME_WIDTH 48
#define FRAME_DELAY_US 200000 // 200 milliseconds between frames

int main(void) {
    void *mlx;
    void *win;
    void *images[NUM_FRAMES];
    char *relative_path = "./attack.xpm";
    int img_width, img_height;
    int current_frame = 0;

    // Initialize MLX
    mlx = mlx_init();

    // Load XPM file containing all character frames
    for (int i = 0; i < NUM_FRAMES; i++) {
        // Calculate position of frame in XPM file
        int frame_offset = FRAME_WIDTH * i;
        images[i] = mlx_xpm_file_to_image(mlx, relative_path + frame_offset, &img_width, &img_height);
        if (!images[i]) {
            // Handle error if image loading fails
            return -1;
        }
    }

    // Create window
    win = mlx_new_window(mlx, img_width, img_height, "Character Animation");

    // Animation loop
    while (1) {
        // Display current frame
        mlx_put_image_to_window(mlx, win, images[current_frame], 0, 0);

        // Increment current frame index and wrap around if necessary
        current_frame = (current_frame + 1) % NUM_FRAMES;

        // Delay between frames
        usleep(FRAME_DELAY_US);
    }

    // Clean up
    mlx_destroy_window(mlx, win);
	mlx_loop(mlx);
    return 0;
}


