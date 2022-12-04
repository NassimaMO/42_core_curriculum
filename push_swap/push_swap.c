/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:06:12 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/04 12:47:10 by nmouslim         ###   ########.fr       */
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

static t_stack	*init_stack(int *a, int *sorted_a, int i, int len)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	ft_bzero(stack, sizeof(t_stack));
	stack->value = a[i];
	stack->index = find_index_num(stack->value, sorted_a, len);
	stack->pos = i;
	return (stack);
}

static void	init_lst(t_list **lst, int *a, int *sorted_a, int len)
{
	int	i;

	i = 0;
	*lst = ft_lstnew(init_stack(a, sorted_a, i, len));
	while (++i < len)
		ft_lstadd_back(lst, ft_lstnew(init_stack(a, sorted_a, i, len)));
	free(a);
	free(sorted_a);
}

int	main(int argc, char **argv)
{
	t_list		*list_a;
	int			*sorted_a;
	int			len;
	int			*a;
	int			i;

	if (!number_checker(argv, argc))
		return (ft_putstr_fd("Error\n", 2), 1);
	a = put_int_tab(argv, argc);
	len = get_num_param(argv, argc);
	if (nums_in_order_rev(a, len) && len > 3)
		return (free(a), rev_scase(len), 0);
	if (nums_in_order(a, len))
		return (free(a), 0);
	sorted_a = tab_dup(a, len);
	ft_sort_int_tab(sorted_a, len);
	i = sorted_a[len / 2];
	init_lst(&list_a, a, sorted_a, len);
	if (len < 3)
		ft_printf("sa\n");
	else if (len == 3)
		algo_three(&list_a);
	else
		tri_positionel(&list_a, len, i);
	return (ft_lstclear(&list_a, free), 0);
}
