#include "../push_swap.h"

static void	commands_the_first(int *a, int *b, int *len_a, int *len_b)
{
	if (*len_a > 2 && num_min_r(a[*len_a - 1], a))
	{
		rrab(a);
		ft_printf("rra\n");
	}
	else if (*len_b >= 2 && !num_max(b[0], b))
	{
		rab(b);
		ft_printf("rb\n");
		return ;
	}
	else if (*len_b > 2 && num_min_r(b[0], b))
	{
		rrab(b);
		ft_printf("rrb\n");
	}
	else if (*len_a >= 2 && (a[0] > a[*len_a - 1] || a[0] > a[1]) && !num_min(a[0], a))
	{
		rab(a);
		ft_printf("ra\n");
		return ;
	}
	else if (*len_a > 2 && !nums_in_order(a, *len_b, 0, 1) && !(*len_a == 3 && a[0] > a[1]))
	{
		pab(b, a);
		(*len_b)++;
		(*len_a)--;
		ft_printf("pb\n");
		return ;
	}
	else if (*len_b >= 1 && nums_in_order(a, *len_b, 0, 1))
	{
		pab(a, b);
		(*len_a)++;
		(*len_b)--;
		ft_printf("pa\n");
		return ;
	}
}

void	super_algo_op(int *a, int *b, int ac)
{
	int	len_a;
	int	len_b;

	len_a = ac - 1;
	len_b = 0;
	while (1)
	{
		if (nums_in_order(a, len_b, 1, 1))
			break ;
		if ((len_b >= 2 && !num_max(b[0], b)) && (len_a >= 2 && (a[0] > a[len_a - 1] || a[0] > a[1]) && !num_min(a[0], a)))
		{
			rr(a, b);
			ft_printf("rr\n");
		}
		else if (len_a > 2 && len_b > 2 && num_min_r(a[len_a - 1], a) && num_min_r(b[0], b))
		{
			rrr(a, b);
			ft_printf("rrr\n");
		}
		else
			commands_the_first(a, b, &len_a, &len_b);
	}
}