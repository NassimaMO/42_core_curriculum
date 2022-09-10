#include "push_swap.h"

static void exec_a(t_stacks *stacks, int i)
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
		while (stacks->a && i < stacks->len_a)
		{
			rrab(stacks->a, stacks->len_a);
			ft_printf("rra\n");
			i++;
		}
	}
	pab(stacks->b, stacks->a, stacks->len_b, stacks->len_a);
	(stacks->len_a)--;
	(stacks->len_b)++;
	ft_printf("pb\n");
}

void	sort_stacks(t_stacks *stacks, int min, int max)
{
	while (!nums_in_order_rev(stacks->b, stacks->len_b) || !nums_in_order(stacks, 0, 1))
	{
		if (stacks->a[0] > stacks->a[1] && stacks->b[0] < stacks->b[1] && stacks->a[0] != max && stacks->b[0] != min)
		{
			ss(stacks->a, stacks->b);
			printf("ss\n");
		}
		else if (stacks->a[0] > stacks->a[1] && stacks->a[0] != max)
		{
			sab(stacks->a);
			printf("sa\n");
		}
		else if (stacks->b[0] < stacks->b[1] && stacks->b[0] != min)
		{
			sab(stacks->b);
			printf("sb\n");
		}
		if (!nums_in_order_rev(stacks->b, stacks->len_b) && !nums_in_order(stacks, 0, 1))
		{
			rr(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
			ft_printf("rr\n");
		}
		else if (!nums_in_order_rev(stacks->b, stacks->len_b))
		{
			rab(stacks->b, stacks->len_b);
			ft_printf("rb\n");
		}
		else if (!nums_in_order(stacks, 0, 1))
		{
			rab(stacks->a, stacks->len_a);
			ft_printf("ra\n");
		}
	}
	/*min = -1;
	while (++min < stacks->len_a)
	ft_printf("a = %d\n", stacks->a[min]);
	ft_printf("\n");
	min = -1;
	while (++min < stacks->len_b)
		ft_printf("b = %d\n", stacks->b[min]);
	ft_printf("\n");*/
	while (stacks->len_b)
	{
		pab(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
		(stacks->len_a)++;
		(stacks->len_b)--;
		ft_printf("pa\n");
	}
}

void	merge_algo(t_stacks *stacks)
{
	int	*x;
	int	len_x;
	int	i;

	i = 0;
	x = ft_dup(stacks->a, stacks->len_a);
	ft_sort_int_tab(x, stacks->len_a);
	len_x = stacks->len_a;
	while (i < stacks->len_a)
	{
		if (stacks->a[i] < x[len_x / 2])
		{
			exec_a(stacks, i);
			i = 0;
		}
		i++;
	}
	sort_stacks(stacks, x[0], x[len_x - 1]);
	free(x);
	/*ft_printf("\n");
	i = -1;
	while (++i < stacks->len_a)
		ft_printf("a = %d\n", stacks->a[i]);
	ft_printf("\n");
	i = -1;
	while (++i < stacks->len_b)
		ft_printf("b = %d\n", stacks->b[i]);
	ft_printf("\n");*/
}









/*i = stacks->len_a / 2;
	while (i >= 0)
	{
		rrab(stacks->a, stacks->len_a);
		ft_printf("rra\n");
		pab(stacks->b, stacks->a, stacks->len_b, stacks->len_a);
		(stacks->len_a)--;
		(stacks->len_b)++;
		ft_printf("pb\n");
		i--;
	}
	i = -1;
	while (++i < len_x)
		ft_printf("x = %d\n", x[i]);
	ft_printf("\n");
	ft_printf("max = %d\n", x[len_x - 1]);
	sleep(5);*/
	//sort_stacks(stacks, x[(len_x - 1) / 2], x[len_x - 1]);