/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:42:25 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/15 16:42:27 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*#include <stdio.h>
int	main()
{
	t_list *lst = malloc(sizeof(t_list) * 2);
	t_list new;

	lst[0].content = "11111";
	lst[0].next = NULL;

	new.content = "22222";
	new.next = NULL;

	ft_lstadd_front(&lst, &new);
//	printf("%s", ((char *)lst[0].content));
//	printf("%s", ((char *)lst[0].next));
//	printf("%s", ((char *)lst[1].content));
//	printf("%s", ((char *)lst[1].next));
}
*/