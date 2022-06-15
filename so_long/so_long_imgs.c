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

/*int render_rect(t_imgs *img, t_rect rect)
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
}*/

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
	printf("line_len = %d\n", data->img.line_len);
	printf("len = %d\n", img->len);
	printf("hei = %d\n\n", img->hei);
	dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	src = img->addr;
	i = 0;
	while (i < SIZE_IMG)
	{
		j = 0;
		while (j < SIZE_IMG)
		{
			if (*((int *)src) >= 0)
				*((int *)dst) = *((int *)src);
			src += (data->img.bpp / 8);
			dst += (data->img.bpp / 8);
			j++;
		}
		i++;
		dst += data->img.line_len - SIZE_IMG;
	}
}

t_lil_imgs	*get_img_ntr(char c, t_data *data)
{
	if (c == '0')
		return (&(data->img_background));
	else if (c == '1')
		return (&(data->img_wall));
	else if (c == 'C')
		return (&(data->img_item));
	else if (c == 'E')
		return (&(data->img_exit));
	else if (c == 'P')
		return (&(data->img_user));
	return (NULL);
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
	/*while (j < data->hei_map)
	{
		i = 0;
		x = 0;
		while (i <= data->len_map)
		{*/
			print_img(get_img_ntr(data->map[l], data), data, x, y);
			/*x += SIZE_IMG;
			l++;
			i++;
		}
		y += SIZE_IMG;
		j++;
	}*/
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

void	free_data_imgs(void *img)
{
	XDestroyImage(((t_img *)img)->image);
	free(img);
}
