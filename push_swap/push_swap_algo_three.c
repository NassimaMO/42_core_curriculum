/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:32:22 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/22 14:09:40 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_algo_three(t_list **list_a, int three_index[3])
{
	if (three_index[0] > three_index[1] && three_index[0] > three_index[2])
	{
		rab(list_a);
		ft_printf("ra\n");
		if (three_index[1] > three_index[2])
		{
			sab(list_a);
			ft_printf("sa\n");
		}
	}
	else if (three_index[1] > three_index[0] && three_index[1] > three_index[2])
	{
		rrab(list_a);
		ft_printf("rra\n");
		if (three_index[2] > three_index[0])
		{
			sab(list_a);
			ft_printf("sa\n");
		}
	}
	else if (three_index[0] > three_index[1])
	{
		sab(list_a);
		ft_printf("sa\n");
	}
}

void	algo_three(t_list **list_a)
{
	int		three_index[3];
	int		i;
	t_list	*tmp;

	tmp = *list_a;
	i = -1;
	while (tmp && ++i < 3)
	{
		three_index[i] = tmp->content->index;
		tmp = tmp->next;
	}
	exec_algo_three(list_a, three_index);
}
