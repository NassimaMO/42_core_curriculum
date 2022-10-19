/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:04:24 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/17 15:37:41 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*pa (push a): Take the first element at the top of b and put it at the top of a
	Do nothing if b is empty.*/
/*pb (push b): Take the first element at the top of a and put it at the top of b
	Do nothing if a is empty.*/
#include "../push_swap.h"

static void	change_pos_p(t_list **lst, int x)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (x < 0)
			tmp->content->pos--;
		else if (tmp->content && x > 0)
			tmp->content->pos++;
		tmp = tmp->next;
	}
}

void	pab(t_list **list_one, t_list **list_two)
{
	t_list	*tmp_one;

	tmp_one = *list_one;
	*list_one = (*list_one)->next;
	change_pos_p(list_one, -1);
	change_pos_p(list_two, 1);
	tmp_one->next = NULL;
	ft_lstadd_front(list_two, tmp_one);
}

/*int	find_index_num(int value, int *a)
{
	int	i;

	i = 0;
	while (a[i] && value != a[i])
		i++;
	return (i + 1);
}

t_stack	*init_stack(char **argv, int *a, int i) //also problem here
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack *));
	stack->value = ft_atoi(argv[i + 1]);
	stack->index = find_index_num(stack->value, a);
	stack->pos = i;
	return (stack);
}

void	put_in_lst(t_list **lst, char **argv, int *a, int i) //problem here too
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

int	main(int argc, char **argv) //problem here
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
	pab(&list_a, &list_b);
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