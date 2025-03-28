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

#include "so_long_bonus.h"

static void	render_imgs_steps(int l, t_data *data)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (i < l)
	{
		if (i + 1 == l)
			print_img(get_img_num_ntr(&data->stct, data->nbr_step, l - 1, 0), \
				data, x, SIZE_IMG * data->hei_map);
		else
			print_img(get_img_num_ntr(&data->stct, data->nbr_step, l - 1, 1), \
				data, x, SIZE_IMG * data->hei_map);
		x += data->stct.img_0.len;
		i++;
	}
}

void	render_steps(t_data *data)
{
	int	x;
	int	i;
	int	l;
	int	tmp;

	l = nbr_case(data->nbr_step);
	tmp = 0;
	while (tmp < l)
	{
		i = data->hei_map * 64;
		while (i < 24 + (64 * data->hei_map))
		{
			x = tmp * 24;
			while (x < (tmp + 1) * 24)
				img_pix_put(&data->img, x++, i, BROWNER_PIXEL);
			i++;
		}
		tmp++;
	}
	render_imgs_steps(l, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
							data->img.mlx_img, 0, 0);
}

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
	return (render_steps(data), mlx_put_image_to_window(data->mlx_ptr, \
			data->win_ptr, data->img.mlx_img, 0, 0), 0);
}

int	moved_img(t_data *data, int img_x, int img_y)
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
				return (l);
			x += SIZE_IMG;
			l++;
		}
		y += SIZE_IMG;
	}
	return (l);
}

int	moved(t_data *data, int img_x, int img_y, int x)
{
	int	l;

	if (data->win_ptr == NULL)
		return (1);
	l = moved_img(data, img_x, img_y);
	if (x == 1)
		sprite_animations(data, l, img_x, img_y);
	else
	{
		background_reset(data, img_x, img_y);
		print_img(get_img_ntr(data->map[l], data), data, img_x * SIZE_IMG, \
								img_y * SIZE_IMG);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->img.mlx_img, 0, 0);
	}
	return (1);
}
