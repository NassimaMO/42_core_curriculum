/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_and_free_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:39:35 by nmouslim          #+#    #+#             */
/*   Updated: 2022/08/21 11:39:37 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_map_tab(t_data *win_param, int argc, char **argv)
{
	if (argc != 2)
		exit(FILE_ERROR);
	if (!file_verif(argv[1]))
		exit(MAP_ERROR);
	size_map(argv[1], &win_param->hei_map, &win_param->len_map);
	win_param->map_file = argv[1];
	win_param->map = put_map_in_tab(win_param);
	if (!win_param->map)
		exit(MALLOC_ERROR);
	if (!map_verif(win_param))
	{
		free(win_param->map);
		exit(MAP_ERROR);
	}
	map_path(win_param);
}

void	init_map(t_data *win_param, int argc, char **argv)
{
	init_map_tab(win_param, argc, argv);
	put_enemy_in_map(win_param);
	win_param->nbr_step = 0;
	win_param->mlx_ptr = mlx_init();
	if (!win_param->mlx_ptr)
	{
		free(win_param->map);
		exit(MLX_ERROR);
	}
	win_param->win_ptr = mlx_new_window(win_param->mlx_ptr, SIZE_IMG * \
		win_param->len_map, SIZE_IMG * win_param->hei_map + 24, "Very Short");
	if (!win_param->win_ptr)
	{
		free(win_param->map);
		free(win_param->win_ptr);
		exit(MLX_ERROR);
	}
	win_param->img.mlx_img = mlx_new_image(win_param->mlx_ptr, SIZE_IMG * \
		win_param->len_map, SIZE_IMG * win_param->hei_map + 24);
	win_param->img.addr = mlx_get_data_addr(win_param->img.mlx_img, \
		&win_param->img.bpp, &win_param->img.line_len, &win_param->img.endian);
}

void	free_all(t_data *win_param)
{
	mlx_destroy_window(win_param->mlx_ptr, win_param->win_ptr);
	free(win_param->map);
	free_data_imgs(win_param->img.mlx_img);
	free_lil_imgs(&win_param->stct);
	mlx_destroy_display(win_param->mlx_ptr);
	free(win_param->mlx_ptr);
}
