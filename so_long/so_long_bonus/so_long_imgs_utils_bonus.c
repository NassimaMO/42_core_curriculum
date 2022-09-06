/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_imgs_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:49:21 by nmouslim          #+#    #+#             */
/*   Updated: 2022/06/18 13:49:23 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_pix_put(t_imgs *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static t_lil_imgs	*get_img_ntr_two(char c, t_data *data)
{
	if (c == 'E')
		return (&(data->stct.img_exit));
	else if (c == 'P')
		return (&(data->stct.img_user));
	else if (c == 'R')
		return (&(data->stct.img_user_mouth_closed));
	else if (c == 'U')
		return (&(data->stct.img_user_up_mouth_closed));
	else if (c == 'D')
		return (&(data->stct.img_user_down_mouth_closed));
	else if (c == 'L')
		return (&(data->stct.img_user_left_mouth_closed));
	else if (c == 'N')
		return (&(data->stct.img_enemy));
	return (NULL);
}

t_lil_imgs	*get_img_ntr(char c, t_data *data)
{
	static int	i = 0;

	if (c == '0')
		return (&(data->stct.img_background));
	else if (c == '2')
		return (&(data->stct.img_background_after));
	else if (c == '1')
	{
		i++;
		if (i <= 1)
			return (&(data->stct.img_wall));
		else
		{
			if (i == 2)
				i = 0;
			return (&(data->stct.img_wall2));
		}
	}
	else if (c == 'C')
		return (&(data->stct.img_item));
	return (get_img_ntr_two(c, data));
}

t_lil_imgs	*return_ntr(t_stct_lil_imgs *img, int n)
{
	if (n == 0)
		return (&img->img_0);
	else if (n == 1)
		return (&img->img_1);
	else if (n == 2)
		return (&img->img_2);
	else if (n == 3)
		return (&img->img_3);
	else if (n == 4)
		return (&img->img_4);
	else if (n == 5)
		return (&img->img_5);
	else if (n == 6)
		return (&img->img_6);
	else if (n == 7)
		return (&img->img_7);
	else if (n == 8)
		return (&img->img_8);
	else if (n == 9)
		return (&img->img_9);
	return (NULL);
}

t_lil_imgs	*get_img_num_ntr(t_stct_lil_imgs *img, int steps, int l, int x)
{
	int			t[10];
	t_lil_imgs	*num;
	static int	i = 0;

	while (steps)
	{
		t[l] = steps % 10;
		steps = steps / 10;
		l--;
	}
	num = return_ntr(img, t[i]);
	if (x == 1)
		i++;
	else
		i = 0;
	return (num);
}
