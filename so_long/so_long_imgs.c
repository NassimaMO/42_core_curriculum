#include "so_long.h"


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

void	print_img(t_imgs *img)
{
	int	x;
	int	y;

	y = 0; 
    while (y < SIZE_IMG)
    {
        x = 0;
        while (x < SIZE_IMG)
        {
            printf("[%d] %d\n", SIZE_IMG * y + x, img->addr[SIZE_IMG * y + x]);
            x++;
        }
        y++;
    }
}

void	image_ntr(char c, t_data *data, int x, int y)
{
	if (c == '1')
	{
		mlx_xpm_file_to_image(data->mlx_ptr, "", SIZE_IMG, SIZE_IMG);
		print_img(&data->img);
	}
	else if (c == '0')
		mlx_xpm_file_to_image(data->mlx_ptr, "", SIZE_IMG, SIZE_IMG);
	else if (c == 'C')
		mlx_xpm_file_to_image(data->mlx_ptr, "", SIZE_IMG, SIZE_IMG);
	else if (c == 'E')
		mlx_xpm_file_to_image(data->mlx_ptr, "", SIZE_IMG, SIZE_IMG);
	else if (c == 'P')
		mlx_xpm_file_to_image(data->mlx_ptr, "", SIZE_IMG, SIZE_IMG);
}

int	render(t_data *data)
{
	int	x;
	int	y;
	int i;
	int	j;

	j = 0;
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, ORANGE_PIXEL);
	while (j < height_size_map())
	{
		i = 0;
		y = (WINDOW_HEIGHT / SIZE_IMG) * j;
		while (i <= width_size_map())
		{
			x = (WINDOW_WIDTH / SIZE_IMG) * i;
			image_ntr(value(data->map_file), data, x, y);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

void	free_data_imgs(void *img)
{
	XDestroyImage(((t_img *)img)->image);
	free(img);
}
