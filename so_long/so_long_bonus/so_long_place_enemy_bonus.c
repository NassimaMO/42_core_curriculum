/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_place_enemy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:43:06 by nmouslim          #+#    #+#             */
/*   Updated: 2022/07/14 13:43:08 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	no_walls_around(t_data *data, int i)
{
	if (data->map[i] == '0')
	{
		if (data->map[i + data->len_map] != '1' || \
			data->map[i - data->len_map] != '1' || \
			data->map[i - 1] != '1' || \
			data->map[i + 1] != '1')
		{
			data->map[i] = 'N';
			return (1);
		}
	}
	return (0);
}

void	put_enemy_in_map(t_data *data)
{
	int	i;
	int	tmp;

	tmp = 0;
	if (strchr(data->map, '0'))
	{
		while (data->map[tmp])
			tmp++;
		tmp /= 2;
		i = tmp;
		while (data->map[i])
		{
			if (no_walls_around(data, i))
				return ;
			i--;
		}
		i = tmp;
		while (data->map[i])
		{
			if (no_walls_around(data, i))
				return ;
			i++;
		}
	}
}
