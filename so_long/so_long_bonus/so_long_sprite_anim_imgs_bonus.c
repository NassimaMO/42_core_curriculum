/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_sprite_anim_imgs_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:11:56 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/07 10:38:06 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display(t_lil_imgs *img, t_data *data, int x, int y)
{
	background_reset(data, x, y);
	print_img(img, data, x * SIZE_IMG, y * SIZE_IMG);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, \
							0, 0);
	mlx_flush_event(data->mlx_ptr);
}

static void	sprite_animations_left(t_data *data, int l, int x, int y)
{
	int	i;

	i = -1;
	if (data->map[l] == 'L')
	{
		while (++i < 60000000)
		{
			if (i == 0)
				display(&data->stct.img_user_left_mouth_half_open, data, \
								x + 1, y);
			else if (i == 20000000)
			{
				background_reset(data, x + 1, y);
				print_img(&data->stct.img_background_after, data, \
							(x + 1) * SIZE_IMG, y * SIZE_IMG);
				display(&data->stct.img_user_left_mouth_closed, data, \
								x, y);
			}
			else if (i == 40000000)
				display(&data->stct.img_user_left, data, x, y);
		}
		return ;
	}
}

static void	sprite_animations_down(t_data *data, int l, int x, int y)
{
	int	i;

	i = -1;
	if (data->map[l] == 'D')
	{
		while (++i < 60000000)
		{
			if (i == 0)
				display(&data->stct.img_user_down_mouth_half_open, data, \
								x, y - 1);
			else if (i == 20000000)
			{
				background_reset(data, x, y - 1);
				print_img(&data->stct.img_background_after, data, \
							x * SIZE_IMG, (y - 1) * SIZE_IMG);
				display(&data->stct.img_user_down_mouth_closed, data, x, \
							y);
			}
			else if (i == 40000000)
				display(&data->stct.img_user_down, data, x, y);
		}
		return ;
	}
	sprite_animations_left(data, l, x, y);
}

static void	sprite_animations_up(t_data *data, int l, int x, int y)
{
	int	i;

	i = -1;
	if (data->map[l] == 'U')
	{
		while (++i < 60000000)
		{
			if (i == 0)
				display(&data->stct.img_user_up_mouth_half_open, data, \
								x, y + 1);
			else if (i == 20000000)
			{
				background_reset(data, x, y + 1);
				print_img(&data->stct.img_background_after, data, \
							x * SIZE_IMG, (y + 1) * SIZE_IMG);
				display(&data->stct.img_user_up_mouth_closed, data, x, y);
			}
			else if (i == 40000000)
				display(&data->stct.img_user_up, data, x, y);
		}
		return ;
	}
	sprite_animations_down(data, l, x, y);
}

void	sprite_animations(t_data *data, int l, int img_x, int img_y)
{
	int	i;

	i = -1;
	if (data->map[l] == 'R')
	{
		while (++i < 60000000)
		{
			if (i == 0)
				display(&data->stct.img_user_mouth_half_open, data, \
								img_x - 1, img_y);
			else if (i == 20000000)
			{
				background_reset(data, img_x - 1, img_y);
				print_img(&data->stct.img_background_after, data, \
							(img_x - 1) * SIZE_IMG, img_y * SIZE_IMG);
				display(&data->stct.img_user_mouth_closed, data, \
								img_x, img_y);
			}
			else if (i == 40000000)
				display(&data->stct.img_user, data, img_x, img_y);
		}
		return ;
	}
	sprite_animations_up(data, l, img_x, img_y);
}
