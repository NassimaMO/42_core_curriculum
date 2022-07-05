/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:11:31 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/27 10:11:33 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_line(char *l)
{
	int		i;
	char	*new;

	i = 0;
	while (l[i] && l[i] != '\n')
		i++;
	new = malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (l[i] && l[i] != '\n')
	{
		new[i] = l[i];
		i++;
	}
	new[i] = '\0';
	free(l);
	return (new);
}

void	ft_rm_bn(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		while (buf[i])
		{
			i++;
			buf[j] = buf[i];
			j++;
		}
	}
	buf[j] = '\0';
}

char	*ft_norminetteuh(char *buf, int fd, int *c)
{
	char	*nl;

	nl = ft_strdup("");
	nl = ft_strjoin(nl, buf);
	*c = 1;
	while (nl && ft_strchr(nl, '\n') == 0 && *c)
	{
		*c = read(fd, buf, BUFFER_SIZE);
		buf[*c] = '\0';
		nl = ft_strjoin(nl, buf);
	}
	return (nl);
}

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*nl;
	int			c;

	if (BUFFER_SIZE <= 0 || read(fd, "", 0) == -1)
		return (NULL);
	nl = ft_norminetteuh(buf[fd], fd, &c);
	if (!c && nl[0] == 0 && nl)
	{
		free(nl);
		return (NULL);
	}
	if (nl)
		nl = ft_line(nl);
	if (!nl)
		return (NULL);
	ft_rm_bn(buf[fd]);
	return (nl);
}
