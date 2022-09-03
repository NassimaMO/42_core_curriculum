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

#include "so_long.h"

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

void	init_call(t_data *data)
{
	data->user = 'P';
	img_init(data, &data->stct.img_wall, "IMAGES/tree.xpm");
	img_init(data, &data->stct.img_item, "IMAGES/item.xpm");
	img_init(data, &data->stct.img_user, "IMAGES/right/pacman.xpm");
	img_init(data, &data->stct.img_user_up, "IMAGES/up/pacmanUp.xpm");
	img_init(data, &data->stct.img_user_down, "IMAGES/down/pacmanDown.xpm");
	img_init(data, &data->stct.img_user_left, "IMAGES/left/pacmanLeft.xpm");
	img_init(data, &data->stct.img_background, "IMAGES/leafy2.xpm");
	img_init(data, &data->stct.img_background_after, "IMAGES/leafy.xpm");
	img_init(data, &data->stct.img_exit, "IMAGES/nice.xpm");
}
