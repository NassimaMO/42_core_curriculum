#include "push_swap.h"

static void exec(void(funct)(int *, int), t_stacks *stacks_data, int i, int x)
{
	if (!x)
	{
		while (stacks_data->a && i > 0)
		{
			funct(stacks_data->a, stacks_data->len_a);
			ft_printf("ra\n");
			i--;
		}
	}
	else if (x)
	{
		while (stacks_data->a && i != stacks_data->len_a)
		{
			funct(stacks_data->a, stacks_data->len_a);
			ft_printf("rra\n");
			i++;
		}
	}
}

static void exec_b(void(funct)(int *, int), t_stacks *stacks_data, int i)
{
	if (stacks_data->b && stacks_data->b[i] && i <= stacks_data->len_b / 2 && i != 0)
	{
		while (stacks_data->b && i > 0)
		{
			funct(stacks_data->b, stacks_data->len_b);
			ft_printf("rb\n");
			i--;
		}
	}
	else if (stacks_data->b && stacks_data->b[i] && i > stacks_data->len_b / 2 && i != 0)
	{
		while (stacks_data->b && i != stacks_data->len_b)
		{
			funct(stacks_data->b, stacks_data->len_b);
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
		if (stacks_data->b && stacks_data->b[i] && i <= stacks_data->len_b / 2 && i != 0)
			exec_b(&rab, stacks_data, i);
		else if (stacks_data->b && stacks_data->b[i] && i > stacks_data->len_b / 2 && i != 0)
			exec_b(&rrab, stacks_data, i);
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
		if (stacks_data->a[i] <= from && stacks_data->a[i] > till)
		{
			if (i <= stacks_data->len_a / 2)
				exec(&rab, stacks_data, i, 0);
			else if (i > stacks_data->len_a / 2)
				exec(&rrab, stacks_data, i, 1);
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

void super_algo_op3(int *a, int *b, int ac)
{
	t_stacks stacks_data;
	int i;
	int	to_fifth;
	int	tmp;
	int	min;
	int fifth_len;

	stacks_data.len_a = ac - 1;
	stacks_data.len_b = 0;
	stacks_data.a = a;
	stacks_data.b = b;
	i = find_num_max(stacks_data.a, stacks_data.len_a); // si nombre trop grand -> time out
	fifth_len = stacks_data.len_a / 5;
	min = find_num_min(stacks_data.a, stacks_data.len_a);
	while (!nums_in_order(&stacks_data, 1, 1) && i >= min)
	{
		to_fifth = 0;
		tmp = i;
		while (stacks_data.a && to_fifth <= fifth_len && i >= min)
		{
			if (find_num(stacks_data.a, i, stacks_data.len_a))
				to_fifth++;
			i--;
		}
		order(&stacks_data, tmp, i);
		order_b(&stacks_data);
	}
	/*i = 0;
	while (stacks_data.a && stacks_data.a[i])
	{
		printf("\na = %d", stacks_data.a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (stacks_data.b && stacks_data.b[i])
	{
		printf("\nb = %d", stacks_data.b[i]);
		i++;
	}
	printf("\n");*/
}
