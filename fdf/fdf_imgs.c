#include "fdf.h"


void	img_pix_put(t_imgs *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int render_rect(t_imgs *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_imgs *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

void	put_columns(int i, int j, int d, t_data *data)
{
	int	tmp;

	tmp = i;
	while (tmp != i + WINDOW_WIDTH / width_size_map())
	{
		if (d == 0)
			render_rect(&data->img, (t_rect){i / 2, j / 2, 2, 2, WHITE_PIXEL});
		else if (d > 0 && d <= 5)
			render_rect(&data->img, (t_rect){i / 2, j / 2, 2, 2, ORANGE_PIXEL});
		else
			render_rect(&data->img, (t_rect){i / 2, j / 2, 2, 2, RED_PIXEL});
		tmp++;
		j += 2;
	}
}

void	put_lines(int *i, int *j, int d, t_data *data)
{
	int tmp_i;
	int tmp_j;

	tmp_i = i;
	tmp_j = j;
	while (tmp_i && tmp_j && tmp_i != i - WINDOW_WIDTH / width_size_map() && tmp_j != j - WINDOW_HEIGHT / height_size_map())
	{
		if (d == 0)
			render_rect(&data->img, (t_rect){tmp_i / 4, tmp_j / 2, 2, 2, WHITE_PIXEL});
		else if (d > 0 && d <= 5)
			render_rect(&data->img, (t_rect){tmp_i / 4, tmp_j / 2, 2, 2, ORANGE_PIXEL});
		else
			render_rect(&data->img, (t_rect){tmp_i / 4, tmp_j / 2, 2, 2, RED_PIXEL});
		tmp_i--;
		tmp_j--;
	}
	i = tmp_i;
	(*j) = tmp_j;
}

/*int	render(t_data *data)
{
	int	x;
	int	y;
	int i;
	int	j;
	int d;

	y = 0;
	x = 0;
	j = WINDOW_HEIGHT / height_size_map();
	i = (WINDOW_WIDTH / width_size_map()) * (height_size_map() * 2);
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, BLACK_PIXEL);
	while (y < height_size_map())
	{
		x = 0;
		while (x <= width_size_map())
		{
			d = value();
			if (d == 0)
				render_rect(&data->img, (t_rect){i / 4, j / 2, 2, 2, WHITE_PIXEL});
			else if (d > 0 && d <= 5)
				render_rect(&data->img, (t_rect){i / 4, j / 2, 2, 2, ORANGE_PIXEL});
			else
				render_rect(&data->img, (t_rect){i / 4, j / 2, 2, 2, RED_PIXEL});
			i -= WINDOW_WIDTH / width_size_map();
			x++;
		}
		y++;
		i = (WINDOW_WIDTH / width_size_map()) * (height_size_map() * 2);
		i -= (((WINDOW_WIDTH / width_size_map()) / 2) * y);
		j += WINDOW_HEIGHT / height_size_map();
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}*/

int	render(t_data *data)
{
	int	x;
	int	y;
	int i;
	int	j;
	int d;
	int 	tmp_i;
	int		tmp_j;

	y = 0;
	x = 0;
	j = 0;
	i = (WINDOW_WIDTH / width_size_map()) * (height_size_map() * 2);
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, BLACK_PIXEL);
	while (y < height_size_map())
	{
		x = 0;
		j += ((WINDOW_HEIGHT / height_size_map()) * width_size_map());
		while (x <= width_size_map())
		{
			d = value();
			if (d == 0)
				render_rect(&data->img, (t_rect){i / 4, j / 2, 2, 2, WHITE_PIXEL});
			else if (d > 0 && d <= 5)
				render_rect(&data->img, (t_rect){i / 4, j / 2, 2, 2, ORANGE_PIXEL});
			else
				render_rect(&data->img, (t_rect){i / 4, j / 2, 2, 2, RED_PIXEL});
	//		put_lines(i, j, d, data);
			x++;
		}
		y++;
		i = (WINDOW_WIDTH / width_size_map()) * (height_size_map() * 2);
		i -= (((WINDOW_WIDTH / width_size_map()) / 2) * y);
		j = (WINDOW_HEIGHT / height_size_map()) * y;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

void	free_data_imgs(void	*img)
{
	XDestroyImage(((t_img *)img)->image);
	free(img);
}
