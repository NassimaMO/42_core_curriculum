/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:06:12 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/13 16:10:37 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	find_index_num(int value, int *a)
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

	stack = malloc(sizeof(t_stack *));
	stack->value = ft_atoi(argv[i + 1]);
	stack->index = find_index_num(stack->value, a);
	stack->pos = i;
	return (stack);
}

static void	put_in_lst(t_list **lst, char **argv, int *a, int i)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list *));
	tmp->content = init_stack(argv, a, i);
	ft_lstadd_back(lst, tmp);
}

static void	init_lst(t_list **lst, char **argv, int *a, int len)
{
	int	i;

	i = -1;
	while (++i < len - 1)
		put_in_lst(lst, argv, a, i);
	free(a);
	return (i);
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
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = put_int_tab(argv, argc);
	ft_sort_int_tab(a, argc - 1);
	if (nums_in_order_rev(a, argc - 1))
		return (free(a), rev_scase(argc - 1), 0);
	i = a[(argc - 1) / 2];
	init_lst(&list_a, argv, argc, a);
	tri_positionel_algo(&list_a, &list_b, argc - 1, i);
	return (0);
}
