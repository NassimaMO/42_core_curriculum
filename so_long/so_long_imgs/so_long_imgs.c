#include "../so_long.h"

void	render_steps(t_data *data)
{
	int	x;
	int	i;
	int	l;

	l = nbr_case(data->nbr_step);
	x = 0;
	i = 0;
	while (i < l)
	{
		if (i + 1 == l)
			print_img(get_img_num_ntr(&data->stct, data->nbr_step, l - 1, 0), data, x, SIZE_IMG * data->hei_map);
		else
			print_img(get_img_num_ntr(&data->stct, data->nbr_step, l - 1, 1), data, x, SIZE_IMG * data->hei_map);
		x += data->stct.img_0.len;
		i++;
	}
}

int	render(t_data *data)
{
	int	x;
	int	y;
	int i;
	int	j;
	int	l;

	j = 0;
	y = 0;
	l = 0;
	x = 0;
	if (data->win_ptr == NULL)
		return (1);
	render_background(data, BROWN_PIXEL);
	while (j < data->hei_map)
	{
		i = 0;
		x = 0;
		while (i < data->len_map)
		{
			print_img(get_img_ntr(data->map[l], data), data, x, y);
			x += SIZE_IMG;
			l++;
			i++;
		}
		y += SIZE_IMG;
		j++;
	}
	render_steps(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
