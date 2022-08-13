/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:48:02 by nmouslim          #+#    #+#             */
/*   Updated: 2022/06/18 13:48:04 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	escape(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
}

int	close_window(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	return (0);
}

void	free_data_imgs(void *img)
{
	XDestroyImage(((t_img *)img)->image);
	free(img);
}

void	free_lil_imgs(t_stct_lil_imgs *imgs)
{
	free_data_imgs(imgs->img_0.mlx_lil_img);
	free_data_imgs(imgs->img_1.mlx_lil_img);
	free_data_imgs(imgs->img_2.mlx_lil_img);
	free_data_imgs(imgs->img_3.mlx_lil_img);
	free_data_imgs(imgs->img_4.mlx_lil_img);
	free_data_imgs(imgs->img_5.mlx_lil_img);
	free_data_imgs(imgs->img_6.mlx_lil_img);
	free_data_imgs(imgs->img_7.mlx_lil_img);
	free_data_imgs(imgs->img_8.mlx_lil_img);
	free_data_imgs(imgs->img_9.mlx_lil_img);
	free_data_imgs(imgs->img_wall.mlx_lil_img);
	free_data_imgs(imgs->img_wall2.mlx_lil_img);
	free_data_imgs(imgs->img_item.mlx_lil_img);
	free_data_imgs(imgs->img_user.mlx_lil_img);
	free_data_imgs(imgs->img_user_up.mlx_lil_img);
	free_data_imgs(imgs->img_user_down.mlx_lil_img);
	free_data_imgs(imgs->img_user_left.mlx_lil_img);
	free_data_imgs(imgs->img_background.mlx_lil_img);
	free_data_imgs(imgs->img_background_after.mlx_lil_img);
	free_data_imgs(imgs->img_exit.mlx_lil_img);
	free_data_imgs(imgs->img_enemy.mlx_lil_img);
}
