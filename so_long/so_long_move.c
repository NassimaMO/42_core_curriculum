/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:47:02 by nmouslim          #+#    #+#             */
/*   Updated: 2022/06/18 13:47:04 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mv_up(t_data *data)
{
	int	l;
	int	tmp;

	l = 0;
	while (data->map[l] && data->map[l] != data->user)
		l++;
	if (data->map[l] == data->user)
	{
		tmp = l;
		l = tmp - (ft_strlen((const char *)data->map) / data->hei_map);
		if (data->map[l] && (data->map[l] == '0' || data->map[l] == 'C' \
			|| data->map[l] == '2'))
		{
			data->user = 'U';
			data->map[l] = data->user;
			data->map[tmp] = '2';
			(data->nbr_step)++;
			moved(data, l % data->len_map, l / data->len_map);
			moved(data, tmp % data->len_map, tmp / data->len_map);
			ft_printf("steps: %d\n", data->nbr_step);
		}
		if (data->map[l] && (data->map[l] == 'E' && !ft_strchr(data->map, 'C')))
			close_window(data);
	}
}

void	mv_left(t_data *data)
{
	int	l;
	int	tmp;

	l = 0;
	while (data->map[l] && data->map[l] != data->user)
		l++;
	if (data->map[l] == data->user)
	{
		tmp = l;
		l--;
		if (data->map[l] && (data->map[l] == '0' || data->map[l] == 'C' \
			|| data->map[l] == '2'))
		{
			data->user = 'L';
			data->map[l] = data->user;
			data->map[tmp] = '2';
			(data->nbr_step)++;
			moved(data, l % data->len_map, l / data->len_map);
			moved(data, tmp % data->len_map, tmp / data->len_map);
			ft_printf("steps: %d\n", data->nbr_step);
		}
		if (data->map[l] && (data->map[l] == 'E' && !ft_strchr(data->map, 'C')))
			close_window(data);
	}
}

void	mv_down(t_data *data)
{
	int	l;
	int	tmp;

	l = 0;
	while (data->map[l] && data->map[l] != data->user)
		l++;
	if (data->map[l] == data->user)
	{
		tmp = l;
		l = tmp + (ft_strlen((const char *)data->map) / data->hei_map);
		if (data->map[l] && (data->map[l] == '0' || data->map[l] == 'C' \
			|| data->map[l] == '2'))
		{
			data->user = 'D';
			data->map[l] = data->user;
			data->map[tmp] = '2';
			(data->nbr_step)++;
			moved(data, l % data->len_map, l / data->len_map);
			moved(data, tmp % data->len_map, tmp / data->len_map);
			ft_printf("steps: %d\n", data->nbr_step);
		}
		if (data->map[l] && (data->map[l] == 'E' && !ft_strchr(data->map, 'C')))
			close_window(data);
	}
}

void	mv_right(t_data *data)
{
	int	l;
	int	tmp;

	l = 0;
	while (data->map[l] && data->map[l] != data->user)
		l++;
	if (data->map[l] == data->user)
	{
		tmp = l;
		l++;
		if (data->map[l] && (data->map[l] == '0' || data->map[l] == 'C' \
			|| data->map[l] == '2'))
		{
			data->user = 'P';
			data->map[l] = data->user;
			data->map[tmp] = '2';
			(data->nbr_step)++;
			moved(data, l % data->len_map, l / data->len_map);
			moved(data, tmp % data->len_map, tmp / data->len_map);
			ft_printf("steps: %d\n", data->nbr_step);
		}
		if (data->map[l] && (data->map[l] == 'E' && !ft_strchr(data->map, 'C')))
			close_window(data);
	}
}
