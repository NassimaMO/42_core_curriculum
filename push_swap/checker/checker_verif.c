/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:06:04 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/04 13:08:17 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	verif_double(char **argv, int argc, int i, int x)
{
	int		n;
	char	**tab_tmp;
	int		num;
	int		w;

	n = 0;
	tab_tmp = ft_split(argv[i], ' ');
	num = ft_atoi(tab_tmp[x]);
	free_tab(tab_tmp);
	while (++n < argc)
	{
		tab_tmp = ft_split(argv[n], ' ');
		w = -1;
		while (tab_tmp[++w])
		{
			if (n != i && x != w && ft_atoi(tab_tmp[w]) == num)
				return (free_tab(tab_tmp), 1);
		}
		free_tab(tab_tmp);
	}
	return (0);
}

int	number_checker(char **argv, int argc)
{
	int				i;
	int				j;
	int				x;
	long long int	nbr;
	char			**tab_tmp;

	i = 0;
	while (++i < argc)
	{
		x = 0;
		j = 0;
		if (!argv[i][j])
			return (0);
		tab_tmp = ft_split(argv[i], ' ');
		while (tab_tmp[x] && tab_tmp[x][j])
		{
			if (!(tab_tmp[x][j] >= '0' && tab_tmp[x][j] <= '9') && \
				!(tab_tmp[x][j] == '-' && j == 0 && tab_tmp[x][j + 1]) && \
				!(tab_tmp[x][j] == '+' && j == 0 && tab_tmp[x][j + 1]))
				return (free_tab(tab_tmp), 0);
			j++;
			if (!tab_tmp[x][j])
			{
				nbr = ft_atoi(tab_tmp[x]);
				if (nbr > INT_MAX || nbr < INT_MIN || \
					verif_double(argv, argc, i, x))
					return (free_tab(tab_tmp), 0);
				x++;
				j = 0;
			}
		}
		free_tab(tab_tmp);
	}
	if (argc <= 2)
		return (0);
	return (1);
}

int	verif_instructs(char **instruct, int length)
{
	int	len;
	int	i;

	i = -1;
	while (++i < length)
	{
		len = ft_strlen(instruct[i]);
		if (ft_strncmp(instruct[i], "rrb\n", len) && \
		ft_strncmp(instruct[i], "sb\n", len) && \
		ft_strncmp(instruct[i], "pa\n", len) && \
		ft_strncmp(instruct[i], "pb\n", len) && \
		ft_strncmp(instruct[i], "rr\n", len) && \
		ft_strncmp(instruct[i], "rrr\n", len) && \
		ft_strncmp(instruct[i], "ss\n", len) && \
		ft_strncmp(instruct[i], "ra\n", len) && \
		ft_strncmp(instruct[i], "rra\n", len) && \
		ft_strncmp(instruct[i], "sa\n", len) && \
		ft_strncmp(instruct[i], "rb\n", len))
			return (1);
	}
	return (0);
}

int	nums_in_order(int *a, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (a[i - 1] > a[i])
			return (ft_putstr_fd("KO\n", 1), 0);
		i++;
	}
	return (ft_putstr_fd("OK\n", 1), 1);
}
