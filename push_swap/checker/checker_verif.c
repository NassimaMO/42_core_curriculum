/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:06:04 by nmouslim          #+#    #+#             */
/*   Updated: 2022/11/25 18:11:09 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	number_checker(char **argv, int argc)
{
	int				i;
	int				j;
	long long int	nbr;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (argv[i][j + 1] == '\0')
			return (0);
		while (argv[i][++j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9') && \
				!(argv[i][j] == '-' && j == 0 && argv[i][j + 1]) && \
				!(argv[i][j] == '+' && j == 0 && argv[i][j + 1]))
				return (0);
		}
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || \
			verif_double(argv[i], argv, argc, i))
			return (0);
	}
	if (argc <= 2)
		exit(0);
	return (1);
}

int	verif_double(char *a, char **argv, int argc, int x)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (i != x && ft_atoi(argv[i]) == ft_atoi(a))
			return (1);
		i++;
	}
	return (0);
}

int	*put_int_tab(char **argv, int argc)
{
	int	*a;
	int	i;
	int	j;

	i = 1;
	j = 0;
	a = malloc(sizeof(int) * (argc - 1));
	if (!a)
		return (0);
	while (i < argc)
	{
		a[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (a);
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
