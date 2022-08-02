#include "so_long.h"

void	init_map(t_data *win_param, int argc, char **argv)
{
	if (argc != 2)
		exit(FILE_ERROR);
	if (!file_verif(argv[1]))
		exit(MAP_ERROR);
	win_param->hei_map = height_size_map(argv[1]);
	win_param->len_map = width_size_map(argv[1]);
	win_param->map_file = argv[1];
	if (!(win_param->map = put_map_in_tab(win_param)))
	{
		free(win_param->map);
		exit(MALLOC_ERROR);
	}
	if (!map_verif(win_param))
	{
		free(win_param->map);
		exit(MAP_ERROR);
	}
	put_enemy_in_map(win_param);
	win_param->nbr_step = 0;
	win_param->mlx_ptr = mlx_init();
	if (!win_param->mlx_ptr)
		exit(MLX_ERROR);
	win_param->win_ptr = mlx_new_window(win_param->mlx_ptr, SIZE_IMG * \
		win_param->len_map, SIZE_IMG * win_param->hei_map + 24, "Very Short");
	if (!win_param->win_ptr)
	{
		free(win_param->win_ptr);
		exit(MLX_ERROR);
	}
	win_param->img.mlx_img = mlx_new_image(win_param->mlx_ptr, SIZE_IMG * \
		win_param->len_map, SIZE_IMG * win_param->hei_map + 24);
	win_param->img.addr = mlx_get_data_addr(win_param->img.mlx_img, \
		&win_param->img.bpp, &win_param->img.line_len, &win_param->img.endian);
}

void	free_all(t_data *win_param)
{
	mlx_destroy_window(win_param->mlx_ptr, win_param->win_ptr);
	free(win_param->map);
	free_data_imgs(win_param->img.mlx_img);
	free_lil_imgs(&win_param->stct);
	mlx_destroy_display(win_param->mlx_ptr);
	free(win_param->mlx_ptr);
}