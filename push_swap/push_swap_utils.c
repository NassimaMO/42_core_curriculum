/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:33:29 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/04 14:32:41 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_pos(t_list **lst)
{
	t_list	*tmp;
	int		i;

	tmp = *lst;
	i = 0;
	while (tmp)
	{
		tmp->content->pos = i++;
		tmp = tmp->next;
	}
}

int	number_checker(char **argv, int argc)
{
	int				i;
	int				j;
	long long int	nbr;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (!argv[i][j + 1])
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
		exit(1);
	while (i < argc)
	{
		a[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (a);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	copie;
	int	index;

	index = 0;
	while (index < size - 1)
	{
		if (tab[index + 1] < tab[index])
		{
			copie = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = copie;
			index = -1;
		}
		index++;
	}
}
