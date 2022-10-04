/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:47:42 by nmouslim          #+#    #+#             */
/*   Updated: 2022/06/18 13:47:44 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	img_init(t_data *data, t_lil_imgs *img, char *path)
{
	img->path = path;
	img->len = 64;
	img->hei = 64;
	img->mlx_lil_img = mlx_xpm_file_to_image(data->mlx_ptr, img->path, \
		&img->len, &img->hei);
	img->addr = mlx_get_data_addr(img->mlx_lil_img, &img->bpp, &img->line_len, \
		&img->endian);
}

static void	img_num_init(t_data *data, t_lil_imgs *img, char *path)
{
	img->path = path;
	img->len = 24;
	img->hei = 24;
	img->mlx_lil_img = mlx_xpm_file_to_image(data->mlx_ptr, img->path, \
		&img->len, &img->hei);
	img->addr = mlx_get_data_addr(img->mlx_lil_img, &img->bpp, &img->line_len, \
		&img->endian);
}

static void	init_call_two(t_data *data)
{
	img_init(data, &data->stct.img_user, "IMAGES/right/pacman.xpm");
	img_init(data, &data->stct.img_user_mouth_closed, \
			"IMAGES/right/pacman_mouth_closed.xpm");
	img_init(data, &data->stct.img_user_mouth_half_open, \
			"IMAGES/right/pacman_mouth_half_open.xpm");
	img_init(data, &data->stct.img_user_up, "IMAGES/up/pacmanUp.xpm");
	img_init(data, &data->stct.img_user_up_mouth_closed, \
			"IMAGES/up/pacman_up_mouth_closed.xpm");
	img_init(data, &data->stct.img_user_up_mouth_half_open, \
			"IMAGES/up/pacman_up_mouth_half_open.xpm");
	img_init(data, &data->stct.img_user_down, "IMAGES/down/pacmanDown.xpm");
	img_init(data, &data->stct.img_user_down_mouth_closed, \
			"IMAGES/down/pacman_down_mouth_closed.xpm");
	img_init(data, &data->stct.img_user_down_mouth_half_open, \
			"IMAGES/down/pacman_down_mouth_half_open.xpm");
	img_init(data, &data->stct.img_user_left, "IMAGES/left/pacmanLeft.xpm");
	img_init(data, &data->stct.img_user_left_mouth_closed, \
			"IMAGES/left/pacman_left_mouth_closed.xpm");
	img_init(data, &data->stct.img_user_left_mouth_half_open, \
			"IMAGES/left/pacman_left_mouth_half_open.xpm");
	img_init(data, &data->stct.img_background, "IMAGES/leafy2.xpm");
	img_init(data, &data->stct.img_background_after, "IMAGES/leafy.xpm");
	img_init(data, &data->stct.img_exit, "IMAGES/nice.xpm");
}

void	init_call(t_data *data)
{
	data->user = 'P';
	img_num_init(data, &data->stct.img_0, "IMAGES/0.xpm");
	img_num_init(data, &data->stct.img_1, "IMAGES/1.xpm");
	img_num_init(data, &data->stct.img_2, "IMAGES/2.xpm");
	img_num_init(data, &data->stct.img_3, "IMAGES/3.xpm");
	img_num_init(data, &data->stct.img_4, "IMAGES/4.xpm");
	img_num_init(data, &data->stct.img_5, "IMAGES/5.xpm");
	img_num_init(data, &data->stct.img_6, "IMAGES/6.xpm");
	img_num_init(data, &data->stct.img_7, "IMAGES/7.xpm");
	img_num_init(data, &data->stct.img_8, "IMAGES/8.xpm");
	img_num_init(data, &data->stct.img_9, "IMAGES/9.xpm");
	img_init(data, &data->stct.img_wall, "IMAGES/tree.xpm");
	img_init(data, &data->stct.img_wall2, "IMAGES/tree2.xpm");
	img_init(data, &data->stct.img_item, "IMAGES/item.xpm");
	img_init(data, &data->stct.img_enemy, "IMAGES/pacman_phantom.xpm");
	img_init(data, &data->stct.img_enemy_left, \
			"IMAGES/pacman_phantom_left.xpm");
	img_init(data, &data->stct.img_enemy_right, \
			"IMAGES/pacman_phantom_right.xpm");
	img_init(data, &data->stct.img_enemy_LR, "IMAGES/pacman_phantom_LR.xpm");
	img_init(data, &data->stct.img_enemy_left_LR, "IMAGES/pacman_phantom_left_LR.xpm");
	img_init(data, &data->stct.img_enemy_right_LR, "IMAGES/pacman_phantom_right_LR.xpm");
	init_call_two(data);
}
