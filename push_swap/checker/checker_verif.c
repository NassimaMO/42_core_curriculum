/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:06:04 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/19 13:55:16 by nmouslim         ###   ########.fr       */
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
		while (argv[i][++j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9') && \
				!(argv[i][j] == '-' && j == 0))
				return (0);
		}
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || \
			verif_double(argv[i], argv, argc, i))
			return (0);
	}
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
