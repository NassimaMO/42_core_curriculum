/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_perf_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:46:35 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/22 13:46:40 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	loop_cost_two(int cost_a, int cost_b, t_list **list_a, \
						t_list **list_b)
{
	while (cost_b > 0)
	{
		rab(list_b);
		ft_printf("rb\n");
		cost_b--;
	}
	while (cost_a < 0)
	{
		rrab(list_a);
		ft_printf("rra\n");
		cost_a++;
	}
	while (cost_a > 0)
	{
		rab(list_a);
		ft_printf("ra\n");
		cost_a--;
	}
}

static void	loop_cost_one(int cost_a, int cost_b, t_list **list_a, \
						t_list **list_b)
{
	while (cost_b < 0 && cost_a < 0)
	{
		rrr(list_a, list_b);
		ft_printf("rrr\n");
		cost_a++;
		cost_b++;
	}
	while (cost_b > 0 && cost_a > 0)
	{
		rr(list_a, list_b);
		ft_printf("rr\n");
		cost_a--;
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrab(list_b);
		ft_printf("rrb\n");
		cost_b++;
	}
	loop_cost_two(cost_a, cost_b, list_a, list_b);
}

void	perform_movement(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;
	int		min_cost;
	int		total_cost;
	int		cost_a;
	int		cost_b;

	tmp = *list_b;
	cost_a = 0;
	cost_b = 0;
	min_cost = 2147483647;
	while (tmp)
	{
		total_cost = get_total_cost(tmp);
		if (total_cost < min_cost)
		{
			cost_a = tmp->content->cost_a;
			cost_b = tmp->content->cost_b;
			min_cost = total_cost;
		}
		tmp = tmp->next;
	}
	loop_cost_one(cost_a, cost_b, list_a, list_b);
}
