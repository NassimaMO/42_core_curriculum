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

int	num_max(int x, int *ab)
{
	int	i;

	i = 1;
	while (ab[i])
	{
		if (ab[i] > x)
			return (0);
		i++;
	}
	return (1);
}

int	num_min(int x, int *ab)
{
	int	i;

	i = 1;
	while (ab[i])
	{
		if (ab[i] < x)
			return (0);
		i++;
	}
	return (1);
}

int	num_min_r(int x, int *ab)
{
	int	i;

	i = 0;
	while (ab[i] && ab[i + 1])
	{
		if (ab[i] < x)
			return (0);
		i++;
	}
	return (1);
}

int	nums_in_order(int *a, int len_b, int x, int y)
{
	int	i;

	i = 1;
	if (len_b != 0 && x)
		return (0);
	while (a[i] && y)
	{
		if (a[i] < a[i - 1])
			return (0);
		i++;
	}
	while (a[i] && !x && !y)
	{
		if (a[i] > a[i - 1])
			return (0);
		i++;
	}
	return (1);
}
