/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:46:48 by nmouslim          #+#    #+#             */
/*   Updated: 2022/06/18 13:46:50 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	width_size_map(char *file)
{
	int		fd;
	char	*line;
	int		x;
	int		i;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	x = 0;
	i = 0;
	while(line && line[i])
	{
		if (line[i] != '\n')
			x++;
		i++;
	}
	close(fd);
	free(line);
	return (x);
}

int	height_size_map(char *file)
{
	int		fd;
	char	*line;
	int		y;

	y = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	free(line);
	return (y);
}

char	value(char *file)
{
	static int	d = 0;
	static int	l = 0;
	int			fd;
	char		*line;
	int			i;
	char		c;

	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line && i < l)
	{
		line = get_next_line(fd);
		i++;
	}
	if (line && !line[d + 1])
	{
		d = 0;
		line = get_next_line(fd);
		l++;
	}
	if (!line)
	{
		d = 0;
		l = 0;
		close(fd);
		fd = open(file, O_RDONLY);
		line = get_next_line(fd);

	}
	if (line && line[d])
	{
		c = line[d];
		d++;
	}
	close(fd);
	free(line);
	return (c);
}

char	*put_map_in_tab(t_data *data)
{
	char	*tab;
	int		i;
	char	d;

	tab = malloc(sizeof(int) * (data->len_map * data->hei_map) + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (i != data->len_map * data->hei_map)
	{
		d = value(data->map_file);
		tab[i] = d;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
