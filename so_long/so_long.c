#include "so_long.h"

int	no_event(t_data *data)
{
	(void) data;
	return (0);
}

int main(int argc, char **argv)
{
	t_data win_param;

	if (argc != 2)
		return (FILE_ERROR);
	if (!file_verif(argv[1]))
		return (MAP_ERROR);
	win_param.hei_map = height_size_map(argv[1]);
	win_param.len_map = width_size_map(argv[1]);
	win_param.map_file = argv[1];
	if (!(win_param.map = put_map_in_tab(&win_param)))
	{
		free(win_param.map);
		return (MALLOC_ERROR);
	}
	if (!map_verif(&win_param))
	{
		free(win_param.map);
		return (MAP_ERROR);
	}
	win_param.nbr_step = 0;
	win_param.mlx_ptr = mlx_init();
	if (!win_param.mlx_ptr)
		return (MLX_ERROR);
	win_param.win_ptr = mlx_new_window(win_param.mlx_ptr, SIZE_IMG * win_param.len_map, SIZE_IMG * win_param.hei_map + 24, "Very Short");
	if (!win_param.win_ptr)
	{
		free(win_param.win_ptr);
		return (MLX_ERROR);
	}
	win_param.img.mlx_img = mlx_new_image(win_param.mlx_ptr, SIZE_IMG * win_param.len_map, SIZE_IMG * win_param.hei_map + 24);
	win_param.img.addr = mlx_get_data_addr(win_param.img.mlx_img, &win_param.img.bpp, &win_param.img.line_len, &win_param.img.endian);
	init_call(&win_param);
	
	mlx_loop_hook(win_param.mlx_ptr, &render, &win_param);
	
	mlx_hook(win_param.win_ptr, KeyPress, KeyPressMask, &input, &win_param);
	mlx_hook(win_param.win_ptr, DestroyNotify, StructureNotifyMask, &close_window, &win_param); //Seg fault
	
	mlx_loop(win_param.mlx_ptr);
	
	mlx_destroy_window(win_param.mlx_ptr, win_param.win_ptr);
	
	free(win_param.map);
	free_data_imgs(win_param.img.mlx_img);
	mlx_destroy_display(win_param.mlx_ptr);
	free(win_param.mlx_ptr);
	return (0);
}
