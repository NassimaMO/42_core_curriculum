#include "push_swap.h"

static void	exec(void (funct)(int *), int *a, int i, int x)
{
	if (!x)
	{
		while (a && a[i - 1])
		{
			funct(a);
			ft_printf("ra\n");
			i--;
		}
	}
	else if (x)
	{
		while (a && a[i])
		{
			funct(a);
			i++;
			ft_printf("rra\n");
		}
	}
}

static void	exec_b(void (funct)(int *), t_stacks *stacks_data, int i)
{
	if (stacks_data->b && stacks_data->b[i] && i <= stacks_data->len_b / 2 && i != 0)
	{
		while (stacks_data->b && stacks_data->b[i - 1])
		{
			funct(stacks_data->b);
			ft_printf("rb\n");
			i--;
		}
	}	
	else if (stacks_data->b && stacks_data->b[i] && i > stacks_data->len_b / 2 && i != 0)
	{
		while (stacks_data->b && stacks_data->b[i])
		{
			funct(stacks_data->b);
			i++;
			ft_printf("rrb\n");
		}
	}
}

static int	find_max(int max, int *b)
{
	int	i;

	i = 0;
	while (b[i])
	{
		if (b[i] == max)
			return (i);
		i++;
	}
	return (-1);
}

static void	order_b(t_stacks *stacks_data)
{
	int	i;

	i = 0;
	while (stacks_data->b && stacks_data->b[i] && !nums_in_order(stacks_data->b, stacks_data->len_b, 0, 0))
	{
		while (stacks_data->b && stacks_data->b[i] && !num_max(stacks_data->b[i], stacks_data->b))
			i++;
		if (stacks_data->b && stacks_data->b[i] && i <= stacks_data->len_b / 2 && i != 0)
			exec_b(&rab, stacks_data, i);
		else if (stacks_data->b && stacks_data->b[i] && i > stacks_data->len_b / 2 && i != 0)
			exec_b(&rrab, stacks_data, i);
		pab(stacks_data->a, stacks_data->b);
		(stacks_data->len_a)++;
		(stacks_data->len_b)--;
		ft_printf("pa\n");
		i = 0;
	}
	while (stacks_data->len_b)
	{
		pab(stacks_data->a, stacks_data->b);
		(stacks_data->len_a)++;
		(stacks_data->len_b)--;
		ft_printf("pa\n");
	}
}

static void order(t_stacks *stacks_data, int from, int till)
{
	int	i;

	i = -1;
	while (stacks_data->a && stacks_data->a[++i])
	{
		if (stacks_data->a[i] > from && stacks_data->a[i] <= till)
		{
			if (!(num_min(stacks_data->a[i], stacks_data->a) && i == 0))
			{
				if (i <= stacks_data->len_a / 2)
					exec(&rab, stacks_data->a, i, 0);
				else if (i > stacks_data->len_a / 2)
					exec(&rrab, stacks_data->a, i, 1);
			}
			if (nums_in_order(stacks_data->a, stacks_data->len_b, 1, 1))
				exit(0);
			pab(stacks_data->b, stacks_data->a);
			(stacks_data->len_a)--;
			(stacks_data->len_b)++;
			ft_printf("pb\n");
			i = -1;
		}
	}
}

void	super_algo_op3(int *a, int *b, int ac)
{
	t_stacks	stacks_data;
	int	max;
	int	i;
	int	j;
	int	fifth_max;

	stacks_data.len_a = ac - 1;
	stacks_data.len_b = 0;
	stacks_data.a = a;
	stacks_data.b = b;
	i = 0;
	while (a && a[i] && !num_max(a[i], a))
		i++;
	max = a[i];
	fifth_max = max / 5;
	i = -1;
	while (!nums_in_order(stacks_data.a, stacks_data.len_b, 1, 1) && i <= max)
	{
		order(&stacks_data, i, i + fifth_max);
		order_b(&stacks_data);

		i += fifth_max;
	}
	while (stacks_data.len_b)
	{
		pab(stacks_data.a, stacks_data.b);
		(stacks_data.len_a)++;
		(stacks_data.len_b)--;
		ft_printf("pa\n");
	}
	i = 0;
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
	printf("\n");
	i = 0;
}
