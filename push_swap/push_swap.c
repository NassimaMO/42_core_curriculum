/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:06:12 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/10 18:27:56 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	find_index_num(int value, int *a)
{
	int	i;

	i = 0;
	while (value != a[i])
		i++;
	return (i);
}

t_stack	*init_stack(char **argv, int *a, int i)
{
	t_stack	*stack;

	stack->value = ft_atoi(argv[i]);
	stack->index = find_index_num(stack->value, a);
	stack->pos = i;
	return (stack);
}

void	put_in_lst(t_list **lst, char **argv, int *a, int i)
{
	t_list	*tmp;

	tmp->content = init_stack(argv, a, i);
	ft_lstadd_back(lst, tmp);
}

void	init_lst(t_list **lst, char **argv, int len)
{
	int	*a;
	int	i;

	i = -1;
	a = put_int_tab(argv, len);
	ft_sort_int_tab(a, len);
	while (++i < len)
		put_in_lst(lst, argv, a, i);
}

int	main(int argc, char **argv)
{
	t_list		*list_a;
	t_list		*list_b;
	int			i;

	i = 0;
	if (argc <= 2)
		return (0);
	if (!number_checker(argv, argc))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	init_lst(&list_a, argv, argc - 1);
	tri_positionel_algo(&list_a, &list_b, argc - 1);
	return (0);
}

/*if (nums_in_order_rev(&list_a, argc - 1))
{
	rev_scase(&list_a, &list_b, argc - 1);
	return (0);
}*/