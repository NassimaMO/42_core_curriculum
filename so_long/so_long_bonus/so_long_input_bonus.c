/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:47:25 by nmouslim          #+#    #+#             */
/*   Updated: 2022/06/18 13:47:27 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	direct_mv(int keysym, t_data *data)
{
	if (keysym == XK_W || keysym == XK_w)
		mv_up(data);
	else if (keysym == XK_A || keysym == XK_a)
		mv_left(data);
	else if (keysym == XK_S || keysym == XK_s)
		mv_down(data);
	else if (keysym == XK_D || keysym == XK_d)
		mv_right(data);
}

int	input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		escape(data);
	else
		direct_mv(keysym, data);
	return (0);
}
