/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:06:12 by nmouslim          #+#    #+#             */
/*   Updated: 2022/11/07 13:47:59 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	find_index_num(int value, int *a, int len)
{
	int	i;

	i = 0;
	while (i < len && value != a[i])
		i++;
	return (i + 1);
}

static t_stack	*init_stack(char **argv, int *a, int i, int len)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	ft_bzero(stack, sizeof(t_stack));
	stack->value = ft_atoi(argv[i + 1]);
	stack->index = find_index_num(stack->value, a, len);
	stack->pos = i;
	return (stack);
}

static void	init_lst(t_list **lst, char **argv, int *a, int len)
{
	int	i;

	i = 0;
	*lst = ft_lstnew(init_stack(argv, a, i, len));
	while (++i < len - 1)
		ft_lstadd_back(lst, ft_lstnew(init_stack(argv, a, i, len - 1)));
	free(a);
}

int	main(int argc, char **argv)
{
	t_list		*list_a;
	t_list		*list_b;
	int			*a;
	int			i;

	if (argc <= 2)
		return (0);
	if (!number_checker(argv, argc))
		return (ft_putstr_fd("Error\n", 2), 1);
	a = put_int_tab(argv, argc);
	if (!a)
		return (1);
	ft_sort_int_tab(a, argc - 1);
	if (nums_in_order_rev(a, argc - 1))
		return (free(a), rev_scase(argc - 1), 0);
	i = a[(argc - 1) / 2];
	init_lst(&list_a, argv, a, argc);
	if (argc - 1 == 3)
		algo_three(&list_a);
	else
		tri_positionel(&list_a, &list_b, argc - 1, i);
	ft_lstclear(&list_a, free);
	return (0);
}

	/*t_list *tmp = list_a;

	while (tmp)
	{
		ft_printf("value = %d, ",tmp->content->value);
		ft_printf("index = %d, ", tmp->content->index);
		ft_printf("pos = %d\n\n", tmp->content->pos);
		tmp = tmp->next;
	}

	tmp = list_b;

	while (tmp)
	{
		ft_printf("value = %d, ",tmp->content->value);
		ft_printf("index = %d, ", tmp->content->index);
		ft_printf("pos = %d\n\n", tmp->content->pos);
		tmp = tmp->next;
	}*/