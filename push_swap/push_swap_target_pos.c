/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_target_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:32:10 by nmouslim          #+#    #+#             */
/*   Updated: 2022/11/07 13:16:03 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_target_pos(t_list *b, t_list *a)
{
	int	pos;
	int	biggest_index_case;
	int	save_index;
	int	sibic;

	save_index = 2147483647;
	sibic = 2147483647;
	while (a)
	{
		if (a->content->index > b->content->index && \
			a->content->index < save_index)
		{
			pos = a->content->pos;
			save_index = a->content->index;
		}
		if (a->content->index < b->content->index && a->content->index < sibic)
		{
			biggest_index_case = a->content->pos;
			sibic = a->content->index;
		}
		a = a->next;
	}
	if (save_index == 2147483647)
		pos = biggest_index_case;
	b->content->target_pos = pos;
}

void	get_target_pos(t_list **list_a, t_list **list_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *list_a;
	tmp_b = *list_b;
	while (tmp_b)
	{
		put_target_pos(tmp_b, tmp_a);
		tmp_a = *list_a;
		tmp_b = tmp_b->next;
	}
}
