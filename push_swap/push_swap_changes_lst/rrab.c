/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:05:05 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/11 13:36:15 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*rra (reverse rotate a): Shift down all elements of stack a by 1. The last
	element becomes the first one.*/
/*rrb (reverse rotate b): Shift down all elements of stack b by 1. The last
	element becomes the first one.*/
#include "../push_swap.h"

void	rrab(t_list *lst)
{
	t_list	*tmp;

	tmp = ft_lstlast(lst);
	ft_lstadd_front(lst, tmp);
	ft_lstdelone(tmp, free);
}