#include "push_swap.h"

void	rev_scase(t_stacks *stacks)
{
	while (stacks->len_a > 2)
	{
		rrab(stacks->a, stacks->len_a);
		ft_printf("rra\n");
		pab(stacks->b, stacks->a, stacks->len_b, stacks->len_a);
		(stacks->len_a)--;
		(stacks->len_b)++;
		ft_printf("pb\n");
	}
	rrab(stacks->a, stacks->len_a);
	ft_printf("rra\n");
	while (stacks->len_b)
	{
		pab(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
		(stacks->len_b)--;
		(stacks->len_a)++;
		ft_printf("pa\n");
	}
}