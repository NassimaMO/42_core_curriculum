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

static void exec_b(t_stacks *stacks, int i)
{
	if (i <= stacks->len_b / 2)
	{
		while (stacks->b && i > 0)
		{
			rab(stacks->b, stacks->len_b);
			ft_printf("rb\n");
			i--;
		}
	}
	else if (i > stacks->len_b / 2)
	{
		while (stacks->b && i < stacks->len_b)
		{
			rrab(stacks->b, stacks->len_b);
			ft_printf("rrb\n");
			i++;
		}
	}
	pab(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
	(stacks->len_b)--;
	(stacks->len_a)++;
	ft_printf("pa\n");
}

static void	push_smaller_than_mpn(t_stacks *stacks, int mpn)
{
	int	i;

	i = 0;
	while (i < stacks->len_a)
	{
		if (stacks->a[i] < mpn)
		{
			exec_a(stacks, i);
			i = -1;
		}
		i++;
	}
}

static void	push_bigger_than_mpn(t_stacks *stacks, int *x, int nic)
{
	int	i;

	i = 0;
	while (i < stacks->len_b && nic >= 0)
	{
		if (stacks->b[i] == x[nic])
		{
			exec_b(stacks, i);
			i = -1;
			nic--;
		}
		i++;
	}
}

static void	push_by_chunks(t_stacks *stacks, int *chunks, int chunks_index, int min)
{
	int	*x;
	int	i;
	int	si;
	int	num_in_chunk;

	i = 0;
	num_in_chunk = 0;
	while (i < stacks->len_b)
	{
		if (stacks->b[i] >= chunks[chunks_index])
			num_in_chunk++;
		i++;
	}
	x = malloc(sizeof(int) * num_in_chunk);
	i = 0;
	si = 0;
	while (si < num_in_chunk)
	{
		if (stacks->b[i] >= chunks[chunks_index])
		{
			x[si] = stacks->b[i];
			si++;
		}
		i++;
	}
	ft_sort_int_tab(x, num_in_chunk);
	if (num_in_chunk)
		push_bigger_than_mpn(stacks, x, num_in_chunk - 1);
	if (chunks_index > 0)
		push_by_chunks(stacks, chunks, chunks_index - 1, min);
	else if (chunks_index == 0 && stacks->len_b)
	{
		chunks[0] = min;
		push_by_chunks(stacks, chunks, chunks_index, min);
	}
	free(x);
}

void    twilio_algo(int *a, int *b, int ac)
{
	t_stacks stacks;
	int *x;
	int	i;
	int	chunks[5];
	int	tmp;

	stacks.len_a = ac - 1;
	stacks.len_b = 0;
	stacks.a = a;
	stacks.b = b;
	
	i  = 0;
	while (stacks.len_a > 2)
	{
		x =	ft_dup(a, stacks.len_a);
		ft_sort_int_tab(x, stacks.len_a);
		if (i == 0)
			tmp = x[0];
		chunks[i] = x[(stacks.len_a) / 2];
		push_smaller_than_mpn(&stacks, chunks[i]);
		free(x);
		i++;
	}
	if (stacks.a[0] > stacks.a[1])
	{
		sab(stacks.a);
		ft_printf("sa\n");
	}
	push_by_chunks(&stacks, chunks, i - 1, tmp);
}