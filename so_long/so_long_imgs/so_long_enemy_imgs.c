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

#include "../so_long.h"

void	enemy_mvments(t_data *data)
{
	static int	i = 0;
	static int	mvUp = 1;
	static int	mvDown = 0;
	static int	mvLeft = 0;
	static int	mvRight = 0;

	if (i >= 100)
	{
		i = 0;
		if (mvUp)
		{
			if (n_mv_up(data))
			{
				mvUp++;
				return ;
			}
			else
			{
				mvLeft++;
				mvUp = 0;
			}
		}
		if (mvLeft)
		{
			if (n_mv_left(data))
			{
				mvLeft++;
				return ;
			}
			else
			{
				mvDown++;
				mvLeft = 0;
			}
		}
		if (mvDown)
		{
			if (n_mv_down(data))
			{
				mvDown++;
				return ;
			}
			else
			{
				mvRight++;
				mvDown = 0;
			}
		}
		if (mvRight)
		{
			if (n_mv_right(data))
			{
				mvRight++;
				return ;
			}
			else
			{
				mvUp++;
				mvRight = 0;
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
		l = strlen((const char *)data->map) / data->hei_map;
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
	}
	return (0);
}

int n_mv_left(t_data *data)
{
	int		l;
	int	tmp;

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
		l = strlen((const char *)data->map) / data->hei_map;
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
	}
	return (0);
}
