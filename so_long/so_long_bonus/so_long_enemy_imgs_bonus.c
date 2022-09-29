/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemy_imgs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:48:44 by nmouslim          #+#    #+#             */
/*   Updated: 2022/06/18 13:48:46 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_mvments(t_data *data)
{
	int	i;

	i = rand() % 4;
	if (i == 0 && n_mv_up(data))
		return ;
	if (i == 1 && n_mv_left(data))
		return ;
	if (i == 2 && n_mv_down(data))
		return ;
	if (i == 3 && n_mv_right(data))
		return ;
	enemy_mvments(data);
}

int	n_mv_up(t_data *data)
{
	int	l;
	int	tmp;

	l = 0;
	while (data->map[l] && data->map[l] != 'N')
		l++;
	if (data->map[l] == 'N')
	{
		tmp = l;
		l = tmp - (ft_strlen((const char *)data->map) / data->hei_map);
		if (data->map[l] && (data->map[l] == '0' || data->map[l] == '2'))
		{
			if (data->map[l] == '0')
				data->map[tmp] = '0';
			if (data->map[l] == '2')
				data->map[tmp] = '2';
			data->map[l] = 'N';
			return (moved(data, l % data->len_map, l / data->len_map, 0), \
				moved(data, tmp % data->len_map, tmp / data->len_map, 0), 1);
		}
		if (data->map[l] == 'P' || data->map[l] == 'U' || data->map[l] == 'L' \
			|| data->map[l] == 'D' || data->map[l] == 'R')
			return (close_window(data), 1);
	}
	return (0);
}

int	n_mv_left(t_data *data)
{
	int		l;
	int		tmp;

	l = 0;
	while (data->map[l] && data->map[l] != 'N')
		l++;
	if (data->map[l] == 'N')
	{
		tmp = l;
		if (data->map[--l] && (data->map[l] == '0' || data->map[l] == '2'))
		{
			if (data->map[l] == '0')
				data->map[tmp] = '0';
			if (data->map[l] == '2')
				data->map[tmp] = '2';
			data->map[l] = 'N';
			moved(data, l % data->len_map, l / data->len_map, 0);
			moved(data, tmp % data->len_map, tmp / data->len_map, 0);
			return (1);
		}
		if (data->map[l] == 'P' || data->map[l] == 'U' || data->map[l] == 'L' \
			|| data->map[l] == 'D' || data->map[l] == 'R')
			return (close_window(data), 1);
	}
	return (0);
}

int	n_mv_down(t_data *data)
{
	int	l;
	int	tmp;

	l = 0;
	while (data->map[l] && data->map[l] != 'N')
		l++;
	if (data->map[l] == 'N')
	{
		tmp = l;
		l = tmp + (ft_strlen((const char *)data->map) / data->hei_map);
		if (data->map[l] && (data->map[l] == '0' || data->map[l] == '2'))
		{
			if (data->map[l] == '0')
				data->map[tmp] = '0';
			if (data->map[l] == '2')
				data->map[tmp] = '2';
			data->map[l] = 'N';
			return (moved(data, l % data->len_map, l / data->len_map, 0), \
				moved(data, tmp % data->len_map, tmp / data->len_map, 0), 1);
		}
		if (data->map[l] == 'P' || data->map[l] == 'U' || data->map[l] == 'L' \
			|| data->map[l] == 'D' || data->map[l] == 'R')
			return (close_window(data), 1);
	}
	return (0);
}

int	n_mv_right(t_data *data)
{
	int	l;
	int	tmp;

	l = 0;
	while (data->map[l] && data->map[l] != 'N')
		l++;
	if (data->map[l] == 'N')
	{
		tmp = l;
		if (data->map[++l] && (data->map[l] == '0' || data->map[l] == '2'))
		{
			if (data->map[l] == '0')
				data->map[tmp] = '0';
			if (data->map[l] == '2')
				data->map[tmp] = '2';
			data->map[l] = 'N';
			moved(data, l % data->len_map, l / data->len_map, 0);
			moved(data, tmp % data->len_map, tmp / data->len_map, 0);
			return (1);
		}
		if (data->map[l] == 'P' || data->map[l] == 'U' || data->map[l] == 'L' \
			|| data->map[l] == 'D' || data->map[l] == 'R')
			return (close_window(data), 1);
	}
	return (0);
}
