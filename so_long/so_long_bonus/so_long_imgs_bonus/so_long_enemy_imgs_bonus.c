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

#include "../so_long_bonus.h"

void	enemy_mvments(t_data *data)
{
	static int	i = 0;
	static int	mv_up = 1;
	static int	mv_down = 0;
	static int	mv_left = 0;
	static int	mv_right = 0;

	if (i >= 100)
	{
		i = 0;
		if (mv_up)
		{
			if (n_mv_up(data))
			{
				mv_up++;
				return ;
			}
			else
			{
				mv_left++;
				mv_up = 0;
			}
		}
		if (mv_left)
		{
			if (n_mv_left(data))
			{
				mv_left++;
				return ;
			}
			else
			{
				mv_down++;
				mv_left = 0;
			}
		}
		if (mv_down)
		{
			if (n_mv_down(data))
			{
				mv_down++;
				return ;
			}
			else
			{
				mv_right++;
				mv_down = 0;
			}
		}
		if (mv_right)
		{
			if (n_mv_right(data))
			{
				mv_right++;
				return ;
			}
			else
			{
				mv_up++;
				mv_right = 0;
			}
		}
	}
	i++;
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
		l = ft_strlen((const char *)data->map) / data->hei_map;
		l = tmp - l;
		if (data->map[l] && (data->map[l] == '0' || data->map[l] == '2'))
		{
			if (data->map[l] == '0')
				data->map[tmp] = '0';
			if (data->map[l] == '2')
				data->map[tmp] = '2';
			data->map[l] = 'N';
			return (1);
		}
		if (data->map[l] == 'P' || data->map[l] == 'U' || data->map[l] == 'L' || data->map[l] == 'D' || data->map[l] == 'R')
			close_window(data);
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
		l--;
		if (data->map[l] && (data->map[l] == '0' || data->map[l] == '2'))
		{
			if (data->map[l] == '0')
				data->map[tmp] = '0';
			if (data->map[l] == '2')
				data->map[tmp] = '2';
			data->map[l] = 'N';
			return (1);
		}
		if (data->map[l] == 'P' || data->map[l] == 'U' || data->map[l] == 'L' || data->map[l] == 'D' || data->map[l] == 'R')
			close_window(data);
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
		l = ft_strlen((const char *)data->map) / data->hei_map;
		l = tmp + l;
		if (data->map[l] && (data->map[l] == '0' || data->map[l] == '2'))
		{
			if (data->map[l] == '0')
				data->map[tmp] = '0';
			if (data->map[l] == '2')
				data->map[tmp] = '2';
			data->map[l] = 'N';
			return (1);
		}
		if (data->map[l] == 'P' || data->map[l] == 'U' || data->map[l] == 'L' || data->map[l] == 'D' || data->map[l] == 'R')
			close_window(data);
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
		l++;
		if (data->map[l] && (data->map[l] == '0' || data->map[l] == '2'))
		{
			if (data->map[l] == '0')
				data->map[tmp] = '0';
			if (data->map[l] == '2')
				data->map[tmp] = '2';
			data->map[l] = 'N';
			return (1);
		}
		if (data->map[l] == 'P' || data->map[l] == 'U' || data->map[l] == 'L' || data->map[l] == 'D' || data->map[l] == 'R')
			close_window(data);
	}
	return (0);
}
