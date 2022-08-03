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

int num_max(int x, int *ab)
{
	int i;

	i = 1;
	while (ab[i])
	{
		if (ab[i] > x)
			return (0);
		i++;
	}
	return (1);
}

int num_min(int x, int *ab)
{
	int i;

	i = 1;
	while (ab[i])
	{
		if (ab[i] < x)
			return (0);
		i++;
	}
	return (1);
}

int num_min_r(int x, int y, int *ab)
{
	int i;

	(void)y;
	i = 0;
	while (ab[i])
	{
		if (ab[i] < x)
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
