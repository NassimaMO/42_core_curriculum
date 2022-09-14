#include "push_swap.h"

static void commands_the_third(t_stacks *stacks)
{
	if (stacks->len_b > 1 && (stacks->b[0] < stacks->b[1] || (num_min(stacks->b[1], stacks->b, stacks->len_b) && stacks->len_b != 2)))
	{
		sab(stacks->b);
		ft_printf("sb\n");
		return;
	}
	else if (stacks->len_b >= 1 && nums_in_order(stacks, 0, 1))
	{
		pab(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
		stacks->len_a++;
		stacks->len_b--;
		ft_printf("pa\n");
		return;
	}
}

static void commands_the_second(t_stacks *stacks)
{
	if (stacks->len_a > 2 && stacks->a[0] > stacks->a[stacks->len_a - 1])
	{
		rrab(stacks->a, stacks->len_a);
		ft_printf("rra\n");
		return;
	}
	else if (stacks->len_a > 1 && (stacks->a[0] > stacks->a[1] || (num_max(stacks->a[1], stacks->a, stacks->len_a) && stacks->len_a != 2)))
	{
		sab(stacks->a);
		ft_printf("sa\n");
		return;
	}
	else if (stacks->len_b > 2 && stacks->b[0] < stacks->b[stacks->len_b - 1] && !num_max(stacks->b[stacks->len_b - 1], stacks->b, stacks->len_b))
	{
		rab(stacks->b, stacks->len_b);
		ft_printf("rb\n");
		return;
	}
	else if (stacks->len_b > 2 && stacks->b[0] < stacks->b[stacks->len_b - 1])
	{
		rrab(stacks->b, stacks->len_b);
		ft_printf("rrb\n");
		return;
	}
	commands_the_third(stacks);
}

static void commands_the_first(t_stacks *stacks, int half)
{
    if (stacks->len_a >= half && !nums_in_order(stacks, 0, 1))
	{
		pab(stacks->b, stacks->a, stacks->len_b, stacks->len_a);
		stacks->len_b++;
		stacks->len_a--;
		ft_printf("pb\n");
		return;
	}
    else if (stacks->len_a > 2 && stacks->a[0] > stacks->a[stacks->len_a - 1] && stacks->len_b > 2 && stacks->b[0] < stacks->b[stacks->len_b - 1] && (!num_max(stacks->b[stacks->len_b - 1], stacks->b, stacks->len_b) && !num_min(stacks->a[stacks->len_a - 1], stacks->a, stacks->len_a)))
    {
        rr(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
        ft_printf("rr\n");
        return;
    }
	else if (stacks->len_a > 2 && stacks->a[0] > stacks->a[stacks->len_a - 1] && stacks->len_b > 2 && stacks->b[0] < stacks->b[stacks->len_b - 1])
	{
		rrr(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
		ft_printf("rrr\n");
		return;
	}
	else if ((stacks->a[0] > stacks->a[1] && stacks->b[0] < stacks->b[1] && stacks->len_b > 1 && stacks->len_a > 1) || (stacks->len_b > 1 && stacks->len_a > 1 && (num_max(stacks->a[1], stacks->a, stacks->len_a) && stacks->len_a != 2) && (num_min(stacks->b[1], stacks->b, stacks->len_b) && stacks->len_b != 2)))
	{
		ss(stacks->a, stacks->b);
		ft_printf("ss\n");
		return;
	}
	else if (stacks->len_a > 2 && stacks->a[0] > stacks->a[stacks->len_a - 1] && !num_min(stacks->a[stacks->len_a - 1], stacks->a, stacks->len_a))
	{
		rab(stacks->a, stacks->len_a);
		ft_printf("ra\n");
		return;
	}
	commands_the_second(stacks);
}

void test_algo_op(t_stacks *stacks)
{
    int half;
    int i;

    half = stacks->len_a / 2;
	while (1)
	{
		if (nums_in_order(stacks, 1, 1))
			break;
		commands_the_first(stacks, half);
        i = -1;
	    while (++i < stacks->len_b)
		    ft_printf("b = %d\n", stacks->b[i]);
	    ft_printf("\n");
        i = -1;
	    while (++i < stacks->len_a)
		    ft_printf("a = %d\n", stacks->a[i]);
	    ft_printf("\n");
	}
}