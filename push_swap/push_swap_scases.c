/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_scases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:40:20 by nmouslim          #+#    #+#             */
/*   Updated: 2022/11/16 15:42:50 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nums_in_order(int *a, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (a[i - 1] > a[i])
			return (0);
		i++;
	}
	return (1);
}

int	nums_in_order_rev(int *a, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (a[i] > a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void	rev_scase(int len_a)
{
	int	len_b;

	len_b = 0;
	while (len_a > 2)
	{
		ft_printf("rra\n");
		ft_printf("pb\n");
		len_a--;
		len_b++;
	}
	ft_printf("rra\n");
	while (len_b)
	{
		ft_printf("pa\n");
		len_b--;
		len_a++;
	}
}
