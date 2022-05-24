/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:11:48 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/15 16:11:50 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

/*
int main()
{
	t_list *nlist = ft_lstnew((void *)"");
	printf("%s\n", (char *)nlist->content);
	printf("%s", (char *)nlist->next);
}*/