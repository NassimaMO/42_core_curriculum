#include "so_long.h"

int	escape(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}