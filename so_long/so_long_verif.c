/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:43:50 by nmouslim          #+#    #+#             */
/*   Updated: 2022/06/18 13:43:52 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_verif(char *file)
{
	int	y;
	int	fd;

	y = 0;
	while (file[y])
		y++;
	if (file[y - 1] != 'r' || file[y - 2] != 'e' || file[y - 3] != 'b')
		return (ft_printf("Error\nWrong file extension.\n"), 0);
	fd = open(file, O_RDONLY);
	if (read(fd, "", 0) == -1)
		return (ft_printf("Error\nFile not found or not valid.\n"), 0);
	return (1);
}

int	map_verif(t_data *data)
{
	int		x;
	int		y;
	char	d;
	int		l;

	y = -1;
	l = 0;
	while (++y != data->hei_map)
	{
		x = -1;
		while (++x < data->len_map)
		{
			d = data->map[l];
			if ((y == 0 && d != '1') || (x == data->len_map - 1 && d != '1') \
				|| (x == 0 && d != '1') || (y == data->hei_map - 1 && d != '1') \
				|| (d != '0' && d != '1' && d != 'C' && d != 'E' && d != 'P'))
				return (ft_printf("Error\nMap not respecting the rules.\n"), 0);
			l++;
		}
	}
	if (x == y || !ft_strchr(data->map, 'E') || !ft_strchr(data->map, 'C') || \
	!ft_strchr(data->map, 'P') || ft_strchr(ft_strchr(data->map, 'P') + 1, 'P') \
	|| ft_strchr(ft_strchr(data->map, 'E') + 1, 'E'))
		return (ft_printf("Error\nMap format or constituants not valid.\n"), 0);
	return (1);
}

static int	search(char *map, char c)
{
	int	i;

	i = 0;
	while (map[i] != c)
		i++;
	return (i);
}

static void	map_backtrack(t_data *data, char *map, int i)
{
	int	x;

	x = (ft_strlen((const char *)data->map) / data->hei_map);
	if (data->map[i + 1] != '1' && map[i + 1] != 'V')
	{
		map[i] = 'V';
		map_backtrack(data, map, i + 1);
	}
	if (data->map[i - 1] != '1' && map[i - 1] != 'V')
	{
		map[i] = 'V';
		map_backtrack(data, map, i - 1);
	}
	if (data->map[i + x] != '1' && map[i + x] != 'V')
	{
		map[i] = 'V';
		map_backtrack(data, map, i + x);
	}
	if (data->map[i - x] != '1' && map[i - x] != 'V')
	{
		map[i] = 'V';
		map_backtrack(data, map, i - x);
	}
	if (data->map[i] == 'E')
		map[i] = 'V';
}

void	map_path(t_data *data)
{
	int		i;
	char	*map;

	i = search(data->map, 'E');
	map = malloc(sizeof(char) * data->hei_map * data->len_map + 1);
	ft_bzero(map, data->hei_map * data->len_map * sizeof(char) + 1);
	map_backtrack(data, map, search(data->map, 'P'));
	if (map[i] != 'V')
	{
		free(data->map);
		free(map);
		ft_printf("Error\nMap does not have a valid path.\n");
		exit(MAP_ERROR);
	}
	free(map);
}
