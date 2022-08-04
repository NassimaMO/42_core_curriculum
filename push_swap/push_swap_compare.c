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

int find_num_min(int *ab, int len)
{
	int	i;

	i = 0;
	while (ab && i != len && !num_min(ab[i], ab, len))
		i++;
	return (ab[i]);
}

int find_num_max(int *ab, int len)
{
	int	i;

	i = 0;
	while (ab && i != len && !num_max(ab[i], ab, len))
		i++;
	return (ab[i]);
}

int	find_num(int *ab, int x, int len)
{
	int i;

	i = 0;
	while (ab && i != len)
	{
		if (ab[i] == x)
			return (1);
		i++;
	}
	return (0);
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
