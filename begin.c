#include "so_long.h"

int	main(void)
{
	t_solong	so_long;
	t_data		img;

	so_long.mlx = mlx_init(); //etablished a connection with the server and malloc big struct, display.
	if (!so_long.mlx)
	{
		write (2, "Error : Malloc\n", 16);
		return (-1);
	}
	so_long.win = mlx_new_window(so_long.mlx, 1920, 1080, "JEU_VIDEAL");
	if (!so_long.win)
	{
		write (2, "Error : Malloc\n", 16);
		mlx_destroy_display(so_long.mlx);
		free(so_long.mlx);
		return (-1);
	}

	img.img = mlx_new_image(so_long.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, img.bits_per_pixel, img.size_line, img.endian);

	mlx_loop(so_long.mlx); //function that keeps the process alive
	mlx_destroy_window(so_long.mlx, so_long.win);
	mlx_destroy_display(so_long.mlx);
	free(so_long.mlx);
}
