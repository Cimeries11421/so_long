#include "so_long.h"



int	main(void)
{
	t_data		img;
	t_content	content;

	content.pos_player[0] = 42;
	content.pos_player[1] = 42;
	//content->so_long = (t_so_long){0};
	content.content.so_long = (t_solong){0}; 
	content.content.so_long.mlx = mlx_init(); //etablished a connection with the server
									  //+ malloc big struct, display.
	if (!content.so_long.mlx)
	{
		write (2, "Error : Malloc\n", 16);
		return (-1);
	}
	content.so_long.win = mlx_new_window(content.so_long.mlx, X_W , Y_W, "JEU_VIDEAL");
	if (!content.so_long.win)
	{
		write (2, "Error : Malloc\n", 16);
		mlx_destroy_display(content.so_long.mlx);
		free(content.so_long.mlx);
		return (-1);
	}
	img.img = mlx_new_image(content.so_long.mlx, 1920, 1080); // A quoi cela sert ? 
	store_content(&content);
	//img.addr = mlx_get_data_addr(img.img, img.bits_per_pixel, img.size_line, img.endian);
	display_image(&content);
	mlx_loop(content.so_long.mlx); //function that keeps the process alive
	//mlx_destroy_window(content->so_long.mlx, so_long.win); //apres la loop pour tour free.
	//lx_destroy_display(content->so_long.mlx);
	//free(content->so_long.mlx);
}
