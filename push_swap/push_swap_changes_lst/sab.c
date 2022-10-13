/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:05:25 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/13 13:06:27 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*sa(swap a) : Swap the first 2 elements at the top of stack a. Do nothing if
	there is only one or no elements.*/
/*sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if
	there is only one or no elements.*/
#include "../push_swap.h"

void	sab(t_list **lst)
{
	t_list 	*tmp;

	(*lst)->content->pos = 1;
	(*lst)->next->content->pos = 0;
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
}
