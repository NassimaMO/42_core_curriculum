/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:25:31 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/16 15:25:33 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cur;
	int		i;

	i = 0;
	cur = lst;
	while (cur)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

/*int main()
{
	t_list *lst = malloc(sizeof(t_list) * 2);
	t_list new;

	lst[0].content = "11111";
	lst[0].next = lst + 1;
	lst[1].content = "22222";
	lst[1].next = NULL;
	printf("%d", ft_lstsize(lst));
}*/