/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:04:46 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/11 13:34:49 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ra (rotate a): Shift up all elements of stack a by 1. The first element
	becomes the last one.*/
/*rb (rotate b): Shift up all elements of stack b by 1.The first element
	becomes the last one.*/
#include "../push_swap.h"

void rab(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	ft_lstadd_back(lst, lst);
	lst = lst->next;
	ft_lstdelone(tmp, free);
}