#include "fdf.h"

int main()
{
	t_data win_param;

	win_param.mlx_ptr = mlx_init();
	if (!win_param.mlx_ptr)
		return (MLX_ERROR);
	win_param.win_ptr = mlx_new_window(win_param.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Fil De Soie");
	if (!win_param.win_ptr)
	{
		free(win_param.win_ptr);
		return (MLX_ERROR);
	}
	win_param.img.mlx_img = mlx_new_image(win_param.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	win_param.img.addr = mlx_get_data_addr(win_param.img.mlx_img, &win_param.img.bpp, &win_param.img.line_len, &win_param.img.endian);
	
	mlx_loop_hook(win_param.mlx_ptr, &render, &win_param);
	
	mlx_hook(win_param.win_ptr, KeyPress, KeyPressMask, &escape, &win_param);
	mlx_hook(win_param.win_ptr, DestroyNotify, StructureNotifyMask, &close_window, &win_param); //Seg fault
	
	mlx_loop(win_param.mlx_ptr);
	
	free_data_imgs(win_param.img);
	mlx_destroy_display(win_param.mlx_ptr);
	free(win_param.mlx_ptr);
	return (0);
}
