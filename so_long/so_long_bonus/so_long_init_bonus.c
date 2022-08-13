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

void	img_init(t_data *data, t_lil_imgs *img, char *path)
{
	img->path = path;
	img->len = 64;
	img->hei = 64;
	img->mlx_lil_img = mlx_xpm_file_to_image(data->mlx_ptr, img->path, \
		&img->len, &img->hei);
	img->addr = mlx_get_data_addr(img->mlx_lil_img, &img->bpp, &img->line_len, \
		&img->endian);
}

void	img_num_init(t_data *data, t_lil_imgs *img, char *path)
{
	img->path = path;
	img->len = 24;
	img->hei = 24;
	img->mlx_lil_img = mlx_xpm_file_to_image(data->mlx_ptr, img->path, \
		&img->len, &img->hei);
	img->addr = mlx_get_data_addr(img->mlx_lil_img, &img->bpp, &img->line_len, \
		&img->endian);
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
	img_init(data, &data->stct.img_user, "IMAGES/pacman.xpm");
	img_init(data, &data->stct.img_user_up, "IMAGES/pacmanUp.xpm");
	img_init(data, &data->stct.img_user_down, "IMAGES/pacmanDown.xpm");
	img_init(data, &data->stct.img_user_left, "IMAGES/pacmanLeft.xpm");
	img_init(data, &data->stct.img_background, "IMAGES/leafy2.xpm");
	img_init(data, &data->stct.img_background_after, "IMAGES/leafy.xpm");
	img_init(data, &data->stct.img_exit, "IMAGES/nice.xpm");
	img_init(data, &data->stct.img_enemy, "IMAGES/pacman_phantom.xpm");
}
