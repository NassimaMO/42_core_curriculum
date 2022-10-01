/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mapsize_verif_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:42:58 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/01 15:43:01 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	cmp_len(int *x, int len)
{
	int	i;

	i = -1;
	while (++i < len - 1)
	{
		if (x[i] != x[i + 1])
			return (0);
	}
	return (1);
}

static void	get_height_map(int *y, char *file)
{
	char	*line;
	int		fd;

	*y = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		(*y)++;
	}
	close(fd);
}

static void	get_all_len_map(int **x, int *i, int y, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	*x = malloc(sizeof(int) * y);
	while (line)
	{
		*i = 0;
		while (line[*i] && line[*i] != '\n')
			(*i)++;
		**x = *i;
		(*x)++;
		free(line);
		line = get_next_line(fd);
	}
	*x -= y;
	free(line);
	close(fd);
}

void	size_map(char *file, int *height, int *width)
{
	int		y;
	int		*x;
	int		i;

	get_height_map(&y, file);
	get_all_len_map(&x, &i, y, file);
	if (!x)
		exit(-1);
	if (!cmp_len(x, y))
	{
		free(x);
		ft_printf("MAP NOT VALID.\n");
		exit(1);
	}
	free(x);
	*height = y;
	*width = i;
}
