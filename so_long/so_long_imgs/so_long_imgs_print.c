#include "../so_long.h"

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 64 * data->hei_map + 24)
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

