/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_compare.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:14:48 by nmouslim          #+#    #+#             */
/*   Updated: 2022/07/04 19:14:49 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int num_max(int x, int *ab, int len)
{
	int i;

	i = 0;
	while (i != len)
	{
		if (ab[i] > x)
			return (0);
		i++;
	}
	return (1);
}

int num_min(int x, int *ab, int len)
{
	int i;

	i = 0;
	while (i != len)
	{
		if (ab[i] < x)
			return (0);
		i++;
	}
	return (1);
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

int	*ft_dup(const int *a, int len)
{
	int	*d;
	int	i;

	i = 0;
	while (i < len)
		i++;
	d = malloc(i * sizeof(int));
	if (!d)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = ((int *)a)[i];
		i++;
	}
	return (d);
}

int	nums_in_order_rev(int *ab, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (ab[i] > ab[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int nums_in_order(t_stacks *stacks, int x, int y)
{
	int i;

	i = 1;
	if (stacks->len_b != 0 && x)
		return (0);
	while (i != stacks->len_a && y)
	{
		if (stacks->a[i] < stacks->a[i - 1])
			return (0);
		i++;
	}
	while (i != stacks->len_a && !x && !y)
	{
		if (stacks->a[i] > stacks->a[i - 1])
			return (0);
		i++;
	}
	return (1);
}
