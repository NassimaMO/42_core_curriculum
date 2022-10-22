/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:31:57 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/22 13:31:58 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_lst_len(t_list **lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	calculate_cost(int pos, int len)
{
	int	i;

	i = 0;
	if (pos > len / 2)
	{
		pos--;
		while (++pos < len)
			i--;
	}
	else
	{
		pos++;
		while (--pos > 0)
			i++;
	}
	return (i);
}

void	calculate_movements_costs(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;
	int		len_a;
	int		len_b;

	tmp = *list_b;
	len_b = get_lst_len(list_b);
	len_a = get_lst_len(list_a);
	while (tmp)
	{
		tmp->content->cost_b = calculate_cost(tmp->content->pos, len_b);
		tmp->content->cost_a = calculate_cost(tmp->content->target_pos, len_a);
		tmp = tmp->next;
	}
}

int	get_total_cost(t_list *lst)
{
	int	a;
	int	b;

	a = lst->content->cost_a;
	b = lst->content->cost_b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}
