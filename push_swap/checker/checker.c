/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:49:49 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/19 13:49:52 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_len(int fd)
{
	int		i;
	char	*str;

	i = 0;
	str = get_next_line(0);
	while (str)
	{
		i++;
		write(fd, str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
	}
	return (i);
}

char	**str_to_tab(int *l)
{
	char	**tab;
	char	*str;
	int		len;
	int		i;
	int		fd;

	i = -1;
	fd = open("./tmp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return (ft_printf("WTF1\n"), NULL);
	len = get_len(fd);
	tab = malloc(sizeof(char *) * len);
	close(fd);
	fd = open("./tmp", O_RDWR, 0644);
	if (fd < 0)
		return (ft_printf("WTF2\n"), NULL);
	str = get_next_line(fd);
	while (str && ++i < len)
	{
		tab[i] = malloc(sizeof(char) * ft_strlen(str));
		tab[i] = str;
		str = get_next_line(fd);
	}
	*l = len;
	close(fd);
	unlink("./tmp");
	return (tab);
}

int	main(int argc, char **argv)
{
	static int	*a;
	static int	*b;
	int			len;
	char		**tab;

	if (argc <= 2)
		return (0);
	if (!number_checker(argv, argc))
		return (ft_putstr_fd("Error\n", 2), 0);
	a = put_int_tab(argv, argc);
	if (!a)
		return (1);
	b = malloc(sizeof(int) * argc);
	if (!b)
		return (free(a), 1);
	ft_bzero(b, sizeof(int));
	tab = str_to_tab(&len);
	if (!tab)
		return (free(a), free(b), 1);
	execute_instruct(tab, len, a, argc - 1, b);
	free(tab);
	free(a);
	free(b);
	return (0);
}
