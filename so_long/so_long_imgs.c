#include "so_long.h"


void	img_pix_put(t_imgs *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		 //big endian, MSB is the leftmost bit 
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		 //little endian, LSB is the leftmost bit 
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 64 * data->hei_map)
	{
		j = 0;
		while (j < 64 * data->len_map)
		{
			img_pix_put(&data->img, j++, i, color);
		}
		++i;
	}
}

void	print_img(t_lil_imgs *img, t_data *data, int x, int y)
{
	char	*dst;
	char	*src;
	int		i;
	int		j;

	if (!img)
		return ;
	dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	src = img->addr;
	i = 0;
	while (i < img->hei)
	{
		j = 0;
		while (j < img->len)
		{
			if (*((int *)src) >= 0)
				*((int *)dst) = *((int *)src);
			src += (data->img.bpp / 8);
			dst += (data->img.bpp / 8);
			j++;
		}
		i++;
		dst += data->img.line_len - img->line_len;
	}
}

t_lil_imgs	*get_img_ntr(char c, t_data *data)
{
	if (c == '0')
		return (&(data->stct.img_background));
	else if (c == '1')
		return (&(data->stct.img_wall));
	else if (c == 'C')
		return (&(data->stct.img_item));
	else if (c == 'E')
		return (&(data->stct.img_exit));
	else if (c == 'P')
		return (&(data->stct.img_user));
	return (NULL);
}

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
		print_img(&(data->stct.img_0), data, x, SIZE_IMG * data->hei_map);
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

void	free_data_imgs(void *img)
{
	XDestroyImage(((t_img *)img)->image);
	free(img);
}
