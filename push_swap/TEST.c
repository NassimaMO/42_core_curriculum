#include "push_swap.h"

static int	get_lst_len(t_list **lst)
{
	int	i;
	t_list *tmp;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static int calculate_cost(int pos, int len)
{
	int	i;

	i = 0;
	if (pos > len / 2)
	{
		pos--;
		while (++pos < len)
			i--;
	}
	else
	{
		pos++;
		while (--pos > 0)
			i++;
	}
	return (i);
}

void	calculate_movements_costs(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;
	int	len_a;
	int	len_b;

	tmp = *list_b;
	len_b = get_lst_len(list_b);
	len_a = get_lst_len(list_a);
	while (tmp)
	{
		tmp->content->cost_b = calculate_cost(tmp->content->pos, len_b);
		tmp->content->cost_a = calculate_cost(tmp->content->target_pos, len_a);
		tmp = tmp->next;
	}
}

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

	/*list_b = malloc(sizeof(t_list));
	ft_bzero(list_b, sizeof(t_list));*/
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
    pab(&list_a, &list_b);
    pab(&list_a, &list_b);
    rrab(&list_a);
    sab(&list_a);
    calculate_movements_costs(&list_a, &list_b);
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
		ft_printf("pos = %d, ", tmp->content->pos);
		ft_printf("cost_a = %d, ", tmp->content->cost_a);
		ft_printf("cost_b = %d\n\n", tmp->content->cost_b);
		tmp = tmp->next;
	}
	ft_printf("\n");
	ft_lstclear(&list_a, free);
	ft_lstclear(&list_b, free);
}