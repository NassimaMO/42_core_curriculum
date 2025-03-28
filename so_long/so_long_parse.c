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

static char	con_value(char *file, int fd, int *l, char *line)
{
	static int	d;
	char		c;

	if (line && line[d] && line[d] != '\n')
	{
		c = line[d];
		d++;
	}
	if (line && (line[d] == '\n' || !line[d]))
	{
		d = 0;
		free(line);
		line = get_next_line(fd);
		(*l)++;
	}
	if (!line)
	{
		d = 0;
		l = 0;
		close(fd);
		fd = open(file, O_RDONLY);
		line = get_next_line(fd);
	}
	free(line);
	return (c);
}

static char	value(char *file)
{
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
		free(line);
		line = get_next_line(fd);
		i++;
	}
	c = con_value(file, fd, &l, line);
	close(fd);
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
