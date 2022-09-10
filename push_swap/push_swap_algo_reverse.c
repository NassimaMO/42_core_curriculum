#include "push_swap.h"

static void exec(t_stacks *stacks_data, int i)
{
	if (i <= stacks_data->len_a / 2)
	{
		while (stacks_data->a && i > 0)
		{
			rab(stacks_data->a, stacks_data->len_a);
			ft_printf("ra\n");
			i--;
		}
	}
	else if (i > stacks_data->len_a / 2)
	{
		while (stacks_data->a && i != stacks_data->len_a)
		{
			rrab(stacks_data->a, stacks_data->len_a);
			ft_printf("rra\n");
			i++;
		}
	}
}

static void exec_b(t_stacks *stacks_data, int i)
{
	if (stacks_data->b && stacks_data->b[i] && i <= stacks_data->len_b / 2 && i != 0)
	{
		while (stacks_data->b && i > 0)
		{
			rab(stacks_data->b, stacks_data->len_b);
			ft_printf("rb\n");
			i--;
		}
	}
	else if (stacks_data->b && stacks_data->b[i] && i > stacks_data->len_b / 2 && i != 0)
	{
		while (stacks_data->b && i != stacks_data->len_b)
		{
			rrab(stacks_data->b, stacks_data->len_b);
			ft_printf("rrb\n");
			i++;
		}
	}
}

static void order_b(t_stacks *stacks_data)
{
	int i;

	i = 0;
	while (stacks_data->b && i != stacks_data->len_b)
	{
		while (stacks_data->b && i != stacks_data->len_b && !num_max(stacks_data->b[i], stacks_data->b, stacks_data->len_b))
			i++;
		exec_b(stacks_data, i);
		pab(stacks_data->a, stacks_data->b, stacks_data->len_a, stacks_data->len_b);
		(stacks_data->len_a)++;
		(stacks_data->len_b)--;
		ft_printf("pa\n");
		i = 0;
	}
}

static void order(t_stacks *stacks_data, int from, int till)
{
	int i;

	i = -1;
	while (stacks_data->a && ++i != stacks_data->len_a)
	{
		if (stacks_data->a[i] <= from && stacks_data->a[i] >= till)
		{
			exec(stacks_data, i);
			if (nums_in_order(stacks_data, 1, 1))
				exit(0);
			pab(stacks_data->b, stacks_data->a, stacks_data->len_b, stacks_data->len_a);
			(stacks_data->len_a)--;
			(stacks_data->len_b)++;
			ft_printf("pb\n");
			i = -1;
		}
	}
}

void super_algo_op3(t_stacks *stacks)
{
	int i;
	int	to_fifth;
	int	tmp;
	int	index;
	int fifth_len;
	int	*x;

	x = ft_dup(stacks->a, stacks->len_a);
	ft_sort_int_tab(x, stacks->len_a);
	i = x[stacks->len_a - 1];
	index = stacks->len_a - 2;
	fifth_len = (stacks->len_a - 1) / 7;
	while (!nums_in_order(stacks, 1, 1) && index >= 0)
	{
		to_fifth = 0;
		tmp = i;
		while (stacks->a && to_fifth <= fifth_len && index >= 0)
		{
			to_fifth++;
			i = x[index];
			index--;
		}
		order(stacks, tmp, i);
		order_b(stacks);
	}
	free(x);
}
