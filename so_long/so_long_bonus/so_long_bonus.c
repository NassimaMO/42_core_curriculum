/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:43:37 by nmouslim          #+#    #+#             */
/*   Updated: 2022/06/18 13:43:40 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	no_input(t_data *data)
{
	enemy_mvments(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	win_param;

	init_map(&win_param, argc, argv);
	init_call(&win_param);
	mlx_loop_hook(win_param.mlx_ptr, &render, &win_param);
	mlx_hook(win_param.win_ptr, KeyPress, KeyPressMask, &input, &win_param);
	mlx_hook(win_param.win_ptr, DestroyNotify, StructureNotifyMask, \
		&close_window, &win_param);
	mlx_loop(win_param.mlx_ptr);
	free_all(&win_param);
	return (0);
}
