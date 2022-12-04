/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tri_positionel_algo.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:10:11 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/04 12:52:00 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_list **list_a)
{
	t_list	*tmp;

	tmp = *list_a;
	while (tmp)
	{
		if (tmp->content->index == 1)
			return (tmp->content->pos);
		tmp = tmp->next;
	}
	return (0);
}

void	put_list_in_order(t_list **list_a, int len)
{
	int	pos;

	pos = find_min_pos(list_a);
	pos = calculate_cost(pos, len);
	while (pos < 0)
	{
		rrab(list_a);
		ft_printf("rra\n");
		pos++;
	}
	while (pos > 0)
	{
		rrab(list_a);
		ft_printf("ra\n");
		pos--;
	}
}

void	algo_exec(t_list **list_a, t_list **list_b, int len)
{
	int	i;

	i = len - 2;
	while (--i)
	{
		get_target_pos(list_a, list_b);
		calculate_movements_costs(list_a, list_b);
		perform_movement(list_a, list_b);
		pab(list_b, list_a, 1);
		ft_printf("pa\n");
	}
	put_list_in_order(list_a, len);
}

void	tri_positionel(t_list **list_a, int len, int mediane)
{
	int		i;
	t_list	*list_b;

	i = -1;
	while (++i < len - 3)
	{
		if (i < len / 2)
		{
			while ((*list_a)->content->value >= mediane)
			{
				rab(list_a);
				ft_printf("ra\n");
			}
			pab(list_a, &list_b, i);
			ft_printf("pb\n");
		}
		else
		{
			pab(list_a, &list_b, i);
			ft_printf("pb\n");
		}
	}
	algo_three(list_a);
	algo_exec(list_a, &list_b, len);
}
