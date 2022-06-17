#include "so_long.h"

void	escape(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
}

int	close_window(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	return (0);
}

void	free_data_imgs(void *img)
{
	XDestroyImage(((t_img *)img)->image);
	free(img);
}