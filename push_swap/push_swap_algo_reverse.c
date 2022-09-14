#include "push_swap.h"

static void exec(t_stacks *stacks, int i)
{
	if (i <= stacks->len_a / 2)
	{
		while (stacks->a && i > 0)
		{
			rab(stacks->a, stacks->len_a);
			ft_printf("ra\n");
			i--;
		}
	}
	else if (i > stacks->len_a / 2)
	{
		while (stacks->a && i != stacks->len_a)
		{
			rrab(stacks->a, stacks->len_a);
			ft_printf("rra\n");
			i++;
		}
	}
}

static void exec_b(t_stacks *stacks, int i)
{
	if (stacks->b && stacks->b[i] && i <= stacks->len_b / 2 && i != 0)
	{
		while (stacks->b && i > 0)
		{
			rab(stacks->b, stacks->len_b);
			ft_printf("rb\n");
			i--;
		}
	}
	else if (stacks->b && stacks->b[i] && i > stacks->len_b / 2 && i != 0)
	{
		while (stacks->b && i != stacks->len_b)
		{
			rrab(stacks->b, stacks->len_b);
			ft_printf("rrb\n");
			i++;
		}
	}
}

static void order_b(t_stacks *stacks)
{
	int i;

	i = 0;
	while (stacks->b && i != stacks->len_b)
	{
		while (stacks->b && i != stacks->len_b && !num_max(stacks->b[i], stacks->b, stacks->len_b))
			i++;
		exec_b(stacks, i);
		pab(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
		(stacks->len_a)++;
		(stacks->len_b)--;
		ft_printf("pa\n");
		i = 0;
	}
}

static void order(t_stacks *stacks, int from, int till)
{
	int i;

	i = -1;
	while (stacks->a && ++i != stacks->len_a)
	{
		if (stacks->a[i] <= from && stacks->a[i] >= till)
		{
			exec(stacks, i);
			if (nums_in_order(stacks, 1, 1))
				exit(0);
			pab(stacks->b, stacks->a, stacks->len_b, stacks->len_a);
			(stacks->len_a)--;
			(stacks->len_b)++;
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
