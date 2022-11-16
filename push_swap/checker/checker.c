/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:49:49 by nmouslim          #+#    #+#             */
/*   Updated: 2022/11/16 16:35:04 by nmouslim         ###   ########.fr       */
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
	int		len;
	int		i;
	int		fd;

	i = 0;
	fd = open("./tmp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return (ft_printf("WTF1\n"), NULL);
	len = get_len(fd);
	tab = malloc(sizeof(char *) * len);
	close(fd);
	fd = open("./tmp", O_RDWR, 0644);
	if (fd < 0)
		return (ft_printf("WTF2\n"), NULL);
	if (len && tab)
	{
		tab[i] = get_next_line(fd);
		while (tab[i] && ++i < len)
			tab[i] = get_next_line(fd);
	}
	*l = len;
	close(fd);
	unlink("./tmp");
	return (tab);
}

int	main(int argc, char **argv)
{
	static int	*a;
	int			len;
	char		**tab;
	int			i;

	if (argc <= 2)
		return (0);
	if (!number_checker(argv, argc))
		return (ft_putstr_fd("Error\n", 2), 0);
	a = put_int_tab(argv, argc);
	if (!a)
		return (1);
	tab = str_to_tab(&len);
	if (!tab)
		return (free(a), 1);
	if (!len)
		return (nums_in_order(a, argc - 1), free(a), free(tab), 1);
	if (verif_instructs(tab, len))
		return (ft_putstr_fd("Error\n", 2), free(a), free(tab), 1);
	execute_instruct(tab, len, a, argc - 1);
	i = -1;
	while (++i < len)
		free(tab[i]);
	return (free(tab), free(a), 0);
}
