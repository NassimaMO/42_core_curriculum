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
	static int	move[4];
	static int	mv_up = 1;
	static int	mv_down;
	static int	mv_left;
	static int	mv_right;
	int			i;

	i = 4;
	if (move[0] == move[2] && move[1] == move[3] && move[0] != move[3])
	{
		if ((move[0] == 1 && move[1] == 3) || (move[0] == 3 && \
			move[1] == 1))
		{
			if (n_mv_left(data))
			{
				while (i > 0)
				{
					move[i] = move[i - 1];
					i--;
				}
				move[0] = 2;
			}
			else if (n_mv_right(data))
			{
				while (i > 0)
				{
					move[i] = move[i - 1];
					i--;
				}
				move[0] = 4;
			}
			else if (move[0] == 1 && n_mv_down(data))
			{
				while (i > 0)
				{
					move[i] = move[i - 1];
					i--;
				}
				move[0] = 3;
			}
			else if (move[0] == 3 && n_mv_up(data))
			{
				while (i > 0)
				{
					move[i] = move[i - 1];
					i--;
				}
				move[0] = 1;
			}
			return ;
		}
		else if ((move[0] == 2 && move[1] == 4) || \
				(move[0] == 4 && move[1] == 2))
		{
			if (n_mv_up(data))
			{
				while (i > 0)
				{
					move[i] = move[i - 1];
					i--;
				}
				move[0] = 1;
			}
			else if (n_mv_down(data))
			{
				while (i > 0)
				{
					move[i] = move[i - 1];
					i--;
				}
				move[0] = 3;
			}
			else if (move[0] == 2 && n_mv_right(data))
			{
				while (i > 0)
				{
					move[i] = move[i - 1];
					i--;
				}
				move[0] = 4;
			}
			else if (move[0] == 4 && n_mv_left(data))
			{
				while (i > 0)
				{
					move[i] = move[i - 1];
					i--;
				}
				move[0] = 2;
			}
			return ;
		}
	}
	while (1)
	{
		if (mv_up)
		{
			if (n_mv_up(data))
			{
				while (i > 0)
				{
					move[i] = move[i - 1];
					i--;
				}
				move[0] = 1;
				mv_up++;
				return ;
			}
			else
			{
				mv_up = 0;
				mv_left++;
			}
		}
		else if (mv_left)
		{
			if (n_mv_left(data))
			{
				while (i > 0)
				{
					move[i] = move[i - 1];
					i--;
				}
				move[0] = 2;
				mv_left++;
				return ;
			}
			else
			{
				mv_left = 0;
				mv_down++;
			}
		}
		else if (mv_down)
		{
			if (n_mv_down(data))
			{
				while (i > 0)
				{
					move[i] = move[i - 1];
					i--;
				}
				move[0] = 3;
				mv_down++;
				return ;
			}
			else
			{
				mv_down = 0;
				mv_right++;
			}
		}
		else if (mv_right)
		{
			if (n_mv_right(data))
			{
				while (i > 0)
				{
					move[i] = move[i - 1];
					i--;
				}
				move[0] = 4;
				mv_right++;
				return ;
			}
			else
			{
				mv_right = 0;
				mv_up++;
			}
		}
	}
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
			moved(data, l % data->len_map, l / data->len_map);
			moved(data, tmp % data->len_map, tmp / data->len_map);
			return (1);
		}
		if (data->map[l] == 'P' || data->map[l] == 'U' || data->map[l] == 'L' \
			|| data->map[l] == 'D' || data->map[l] == 'R')
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
			moved(data, l % data->len_map, l / data->len_map);
			moved(data, tmp % data->len_map, tmp / data->len_map);
			return (1);
		}
		if (data->map[l] == 'P' || data->map[l] == 'U' || data->map[l] == 'L' \
			|| data->map[l] == 'D' || data->map[l] == 'R')
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
			moved(data, l % data->len_map, l / data->len_map);
			moved(data, tmp % data->len_map, tmp / data->len_map);
			return (1);
		}
		if (data->map[l] == 'P' || data->map[l] == 'U' || data->map[l] == 'L' \
			|| data->map[l] == 'D' || data->map[l] == 'R')
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
			moved(data, l % data->len_map, l / data->len_map);
			moved(data, tmp % data->len_map, tmp / data->len_map);
			return (1);
		}
		if (data->map[l] == 'P' || data->map[l] == 'U' || data->map[l] == 'L' \
			|| data->map[l] == 'D' || data->map[l] == 'R')
			close_window(data);
	}
	return (0);
}
