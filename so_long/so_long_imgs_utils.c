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

#include "so_long.h"

void	img_pix_put(t_imgs *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

t_lil_imgs	*get_img_ntr(char c, t_data *data)
{
	if (c == '0')
		return (&(data->stct.img_background));
	else if (c == '2')
		return (&(data->stct.img_background_after));
	else if (c == '1')
		return (&(data->stct.img_wall));
	else if (c == 'C')
		return (&(data->stct.img_item));
	else if (c == 'E')
		return (&(data->stct.img_exit));
	else if (c == 'P')
		return (&(data->stct.img_user));
	else if (c == 'U')
		return (&(data->stct.img_user_up));
	else if (c == 'D')
		return (&(data->stct.img_user_down));
	else if (c == 'L')
		return (&(data->stct.img_user_left));
	return (NULL);
}
