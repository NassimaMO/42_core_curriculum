/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:05:05 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/14 16:57:00 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*rra (reverse rotate a): Shift down all elements of stack a by 1. The last
	element becomes the first one.*/
/*rrb (reverse rotate b): Shift down all elements of stack b by 1. The last
	element becomes the first one.*/
#include "../push_swap.h"

void	nullify_next_before_last(t_list **lst, t_list *t)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->next->content->value == t->content->value)
		{
			ft_printf("tmp_before_last = %d\n", tmp->next->content->value);
			tmp->next = NULL;
			return ;
		}
		tmp = tmp->next;
	}
}

void	rrab(t_list **lst)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst);
	ft_printf("tmp_last = %d\n", tmp->content->value);
	nullify_next_before_last(lst, tmp);
	ft_lstadd_front(lst, tmp);
	change_pos(lst);
}

/*int	find_index_num(int value, int *a)
{
	int	i;

	i = 0;
	while (a[i] && value != a[i])
		i++;
	return (i + 1);
}

t_stack	*init_stack(char **argv, int *a, int i)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack *));
	stack->value = ft_atoi(argv[i + 1]);
	stack->index = find_index_num(stack->value, a);
	stack->pos = i;
	return (stack);
}

void	put_in_lst(t_list **lst, char **argv, int *a, int i)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list *));
	tmp->content = init_stack(argv, a, i);
	ft_lstadd_back(lst, tmp);
}

void	init_lst(t_list **lst, char **argv, int len)
{
	int	*a;
	int	i;

	i = -1;
	a = put_int_tab(argv, len);
	ft_sort_int_tab(a, len - 1);
	while (++i < len - 1)
		put_in_lst(lst, argv, a, i);
	free(a);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*tmp;

	init_lst(&list_a, argv, argc);
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
	rrab(&list_a);
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
		ft_printf("value = %d, ",tmp->content->value);
		ft_printf("index = %d, ", tmp->content->index);
		ft_printf("pos = %d\n\n", tmp->content->pos);
		tmp = tmp->next;
	}
	ft_printf("\n");
	ft_lstclear(&list_a, free);
	ft_lstclear(&list_b, free);
}*/