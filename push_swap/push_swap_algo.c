/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:05:53 by nmouslim          #+#    #+#             */
/*   Updated: 2022/07/04 19:05:55 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_op(int *a, int *b, int ac)
{
	int	len_a;
	int	len_b;

	len_a = ac - 1;
	len_b = 0;
	while (1)
	{
		if (nums_in_order(a, len_b, 1, 1))
			break ;
		if (len_a > 2 && a[0] > a[len_a - 1] && len_b > 2 \
			&& b[0] < b[len_b - 1] && (!num_max(b[len_b - 1], b) \
			&& !num_min(a[len_a - 1], a)))
		{
			rr(a, b);
			ft_printf("rr\n");
			return ;
		}
		else
			commands_the_first(a, b, &len_a, &len_b);
	}
}

void	commands_the_first(int *a, int *b, int *len_a, int *len_b)
{
	if (*len_a > 2 && a[0] > a[*len_a - 1] \
		&& *len_b > 2 && b[0] < b[*len_b - 1])
	{
		rrr(a, b);
		ft_printf("rrr\n");
		return ;
	}
	else if ((a[0] > a[1] && b[0] < b[1] && *len_b > 1 && *len_a > 1) \
		|| (*len_b > 1 && *len_a > 1 && (num_max(a[1], a) && *len_a != 2) \
		&& (num_min(b[1], b) && *len_b != 2)))
	{
		ss(a, b);
		ft_printf("ss\n");
		return ;
	}
	else if (*len_a > 2 && a[0] > a[*len_a - 1] && !num_min(a[*len_a - 1], a))
	{
		rab(a);
		ft_printf("ra\n");
		return ;
	}
	commands_the_second(a, b, len_a, len_b);
}

void	commands_the_second(int *a, int *b, int *len_a, int *len_b)
{
	if (*len_a > 2 && a[0] > a[*len_a - 1])
	{
		rrab(a);
		ft_printf("rra\n");
		return ;
	}
	else if (*len_a > 1 && (a[0] > a[1] || (num_max(a[1], a) && *len_a != 2)))
	{
		sab(a);
		ft_printf("sa\n");
		return ;
	}
	else if (*len_b > 2 && b[0] < b[*len_b - 1] && !num_max(b[*len_b - 1], b))
	{
		rab(b);
		ft_printf("rb\n");
		return ;
	}
	else if (*len_b > 2 && b[0] < b[*len_b - 1])
	{
		rrab(b);
		ft_printf("rrb\n");
		return ;
	}
	commands_the_third(a, b, len_a, len_b);
}

void	commands_the_third(int *a, int *b, int *len_a, int *len_b)
{
	if (*len_b > 1 && (b[0] < b[1] || (num_min(b[1], b) && *len_b != 2)))
	{
		sab(b);
		ft_printf("sb\n");
		return ;
	}
	else if (*len_b >= 1 && nums_in_order(a, *len_b, 0, 1))
	{
		pab(a, b);
		(*len_a)++;
		(*len_b)--;
		ft_printf("pa\n");
		return ;
	}
	else if (*len_a >= 1 && !nums_in_order(a, *len_b, 0, 1))
	{
		pab(b, a);
		(*len_b)++;
		(*len_a)--;
		ft_printf("pb\n");
		return ;
	}
}
