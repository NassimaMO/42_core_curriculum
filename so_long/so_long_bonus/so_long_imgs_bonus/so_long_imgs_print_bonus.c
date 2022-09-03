/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_imgs_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:49:04 by nmouslim          #+#    #+#             */
/*   Updated: 2022/06/18 13:49:06 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	background_reset(t_data *data, int img_x, int img_y)
{
	int	i;
	int	j;

	i = img_y * 64;
	while (i < 64 * (img_y + 1))
	{
		j = img_x * 64;
		while (j < 64 * (img_x + 1))
			img_pix_put(&data->img, j++, i, BROWNER_PIXEL);
		i++;
	}
}

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
