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

static void commands_the_third(t_stacks *stacks)
{
	if (stacks->len_b > 1 && (stacks->b[0] < stacks->b[1] || (num_min(stacks->b[1], stacks->b, stacks->len_b) && stacks->len_b != 2)))
	{
		sab(stacks->b);
		ft_printf("sb\n");
		return;
	}
	else if (stacks->len_b >= 1 && nums_in_order(stacks, 0, 1))
	{
		pab(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
		stacks->len_a++;
		stacks->len_b--;
		ft_printf("pa\n");
		return;
	}
	else if (stacks->len_a >= 1 && !nums_in_order(stacks, 0, 1))
	{
		pab(stacks->b, stacks->a, stacks->len_b, stacks->len_a);
		stacks->len_b++;
		stacks->len_a--;
		ft_printf("pb\n");
		return;
	}
}

static void commands_the_second(t_stacks *stacks)
{
	if (stacks->len_a > 2 && stacks->a[0] > stacks->a[stacks->len_a - 1])
	{
		rrab(stacks->a, stacks->len_a);
		ft_printf("rra\n");
		return;
	}
	else if (stacks->len_a > 1 && (stacks->a[0] > stacks->a[1] || (num_max(stacks->a[1], stacks->a, stacks->len_a) && stacks->len_a != 2)))
	{
		sab(stacks->a);
		ft_printf("sa\n");
		return;
	}
	else if (stacks->len_b > 2 && stacks->b[0] < stacks->b[stacks->len_b - 1] && !num_max(stacks->b[stacks->len_b - 1], stacks->b, stacks->len_b))
	{
		rab(stacks->b, stacks->len_b);
		ft_printf("rb\n");
		return;
	}
	else if (stacks->len_b > 2 && stacks->b[0] < stacks->b[stacks->len_b - 1])
	{
		rrab(stacks->b, stacks->len_b);
		ft_printf("rrb\n");
		return;
	}
	commands_the_third(stacks);
}

static void commands_the_first(t_stacks *stacks)
{
	if (stacks->len_a > 2 && stacks->a[0] > stacks->a[stacks->len_a - 1] && stacks->len_b > 2 && stacks->b[0] < stacks->b[stacks->len_b - 1])
	{
		rrr(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
		ft_printf("rrr\n");
		return;
	}
	else if ((stacks->a[0] > stacks->a[1] && stacks->b[0] < stacks->b[1] && stacks->len_b > 1 && stacks->len_a > 1) || (stacks->len_b > 1 && stacks->len_a > 1 && (num_max(stacks->a[1], stacks->a, stacks->len_a) && stacks->len_a != 2) && (num_min(stacks->b[1], stacks->b, stacks->len_b) && stacks->len_b != 2)))
	{
		ss(stacks->a, stacks->b);
		ft_printf("ss\n");
		return;
	}
	else if (stacks->len_a > 2 && stacks->a[0] > stacks->a[stacks->len_a - 1] && !num_min(stacks->a[stacks->len_a - 1], stacks->a, stacks->len_a))
	{
		rab(stacks->a, stacks->len_a);
		ft_printf("ra\n");
		return;
	}
	commands_the_second(stacks);
}

void algo_op(int *a, int *b, int ac)
{
	t_stacks stacks;

	stacks.a = a;
	stacks.b = b;
	stacks.len_a = ac - 1;
	stacks.len_b = 0;
	while (1)
	{
		if (nums_in_order(&stacks, 1, 1))
			break;
		/*ft_printf("\n%d", stacks.a[0]);
		ft_printf("\n%d", stacks.a[1]);
		ft_printf("\n%d\n\n", stacks.a[2]);*/
		if (stacks.len_a > 2 && stacks.a[0] > stacks.a[stacks.len_a - 1] && stacks.len_b > 2 && stacks.b[0] < stacks.b[stacks.len_b - 1] && (!num_max(stacks.b[stacks.len_b - 1], stacks.b, stacks.len_b) && !num_min(stacks.a[stacks.len_a - 1], stacks.a, stacks.len_a)))
		{
			rr(stacks.a, stacks.b, stacks.len_a, stacks.len_b);
			ft_printf("rr\n");
			return;
		}
		else
			commands_the_first(&stacks);
	}
}