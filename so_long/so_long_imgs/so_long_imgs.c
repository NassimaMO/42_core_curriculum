/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:49:41 by nmouslim          #+#    #+#             */
/*   Updated: 2022/06/18 13:49:42 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	l;

	j = -1;
	y = 0;
	l = -1;
	if (data->win_ptr == NULL)
		return (1);
	render_background(data, BROWNER_PIXEL);
	while (++j < data->hei_map)
	{
		i = -1;
		x = 0;
		while (++i < data->len_map)
		{
			print_img(get_img_ntr(data->map[++l], data), data, x, y);
			x += SIZE_IMG;
		}
		y += SIZE_IMG;
	}
	return (mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->img.mlx_img, 0, 0), 0);
}

static void	moved_img(t_data *data, int img_x, int img_y)
{
	int	j;
	int	i;
	int	x;
	int	y;
	int	l;

	y = 0;
	l = 0;
	j = -1;
	while (++j < data->hei_map)
	{
		i = -1;
		x = 0;
		while (++i < data->len_map)
		{
			if (img_y == j && img_x == i)
			{
				print_img(get_img_ntr(data->map[l], data), data, x, y);
				break ;
			}
			x += SIZE_IMG;
			l++;
		}
		y += SIZE_IMG;
	}
}

int	moved(t_data *data, int img_x, int img_y)
{
	int	i;
	int	j;

	if (data->win_ptr == NULL)
		return (1);
	i = img_y * 64;
	while (i < 64 * (img_y + 1))
	{
		j = img_x * 64;
		while (j < 64 * (img_x + 1))
			img_pix_put(&data->img, j++, i, BROWNER_PIXEL);
		i++;
	}
	moved_img(data, img_x, img_y);
	return (mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->img.mlx_img, 0, 0), 1);
}
