/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:04:46 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/15 13:46:52 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ra (rotate a): Shift up all elements of stack a by 1. The first element
	becomes the last one.*/
/*rb (rotate b): Shift up all elements of stack b by 1.The first element
	becomes the last one.*/
#include "../push_swap.h"

void rab(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	ft_lstadd_back(lst, tmp);
	*lst = tmp->next;
	tmp->next = NULL;
	change_pos(lst);
}

/*static int	find_index_num(int value, int *a)
{
	int	i;

	i = 0;
	while (a[i] && value != a[i])
		i++;
	return (i + 1);
}

static t_stack	*init_stack(char **argv, int *a, int i)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	ft_bzero(stack, sizeof(t_stack));
	stack->value = ft_atoi(argv[i + 1]);
	stack->index = find_index_num(stack->value, a);
	stack->pos = i;
	return (stack);
}

static void	init_lst(t_list **lst, char **argv, int *a, int len)
{
	int	i;

	i = 0;
	*lst = ft_lstnew(init_stack(argv, a, i));
	while (++i < len - 1)
		ft_lstadd_back(lst, ft_lstnew(init_stack(argv, a, i)));
	free(a);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*tmp;
	int		*a;

	list_b = malloc(sizeof(t_list));
	ft_bzero(list_b, sizeof(t_list));
	a = put_int_tab(argv, argc);
	ft_sort_int_tab(a, argc - 1);
	init_lst(&list_a, argv, a, argc);
	tmp = list_a;
	ft_printf("before\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
	while (tmp)
	{
		ft_printf("value = %d, ",tmp->content->value);
		ft_printf("index = %d, ", tmp->content->index);
		ft_printf("pos = %d\n\n", tmp->content->pos);
		tmp = tmp->next;
	}
	ft_printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n\n");
	rab(&list_a);
	tmp = list_a;
	ft_printf("after_a\n");
	while (tmp)
	{
		ft_printf("value = %d, ",tmp->content->value);
		ft_printf("index = %d, ", tmp->content->index);
		ft_printf("pos = %d\n\n", tmp->content->pos);
		tmp = tmp->next;
	}
	ft_printf("\n");
	rab(&list_a);
		tmp = list_a;
	ft_printf("after_a\n");
	while (tmp)
	{
		ft_printf("value = %d, ",tmp->content->value);
		ft_printf("index = %d, ", tmp->content->index);
		ft_printf("pos = %d\n\n", tmp->content->pos);
		tmp = tmp->next;
	}
	ft_printf("\n");
	tmp = list_b;
	ft_printf("after_b\n");
	while (tmp)
	{
		//ft_printf("value = %d, ",tmp->content->value);
		//ft_printf("index = %d, ", tmp->content->index);
		//ft_printf("pos = %d\n\n", tmp->content->pos);
		tmp = tmp->next;
	}
	ft_printf("\n");
	ft_lstclear(&list_a, free);
	ft_lstclear(&list_b, free);
}*/