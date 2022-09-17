/*#include "push_swap.h"

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

static void	push_bigger_than_mpn(t_stacks *stacks, int *x, int nic, int mpn)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = nic;
	while (i < stacks->len_b && nic >= 0)
	{
		if (stacks->b[i] == x[nic] && x[nic] >= mpn)
		{
			//ft_printf("|||||||||xn = %d\n", x[nic]);
			exec_b(stacks, i);
			i = -1;
			nic--;
		}
		i++;
	}
	if (nic > 0)
	{
		//ft_printf("a[0] = %d, x[0] = %d, mpn = %d, |tmp/nic = %d/%d|, fthkktjg = %d\n", stacks->a[0], x[0], mpn, tmp, nic, x[(tmp - nic) - nic / 2]);
		push_bigger_than_mpn(stacks, x, nic, x[(tmp - nic) - nic / 2]);
	}
	else if (nic == 0)
	{
		//ft_printf("a[0] = %d, x[0] = %d, mpn = %d, |tmp/nic = %d/%d|, fthkktjg = %d\n", stacks->a[0], x[0], mpn, tmp, nic, x[nic]);
		push_bigger_than_mpn(stacks, x, nic, x[nic]);
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
	//ft_printf("|````||``|``||``||``````````````|ci = %d, nic = %d\n", chunks[chunks_index], num_in_chunk);
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
	i = -1;
	while (++i <= stacks->len_a)
		ft_printf("a = %d\n", stacks->a[i]);
	ft_printf("\n");
	sleep(1);
	ft_sort_int_tab(x, num_in_chunk);
	if (num_in_chunk)
		push_bigger_than_mpn(stacks, x, num_in_chunk - 1, x[num_in_chunk / 2]);
	if (chunks_index > 0)
		push_by_chunks(stacks, chunks, chunks_index - 1, min);
	else if (chunks_index == 0 && stacks->len_b)
	{
		chunks[0] = min;
		push_by_chunks(stacks, chunks, chunks_index, min);
	}
	free(x);
}

void    ayo_algo(t_stacks *stacks)
{
	int *x;
	int	i;
	//int	t;
	int	chunks[5];
	int	tmp;

	i  = 0;
    x =	ft_dup(stacks->a, stacks->len_a);
	ft_sort_int_tab(x, stacks->len_a);
    tmp = stacks->len_a - 1;
	while (stacks->len_a > 2)
	{
		chunks[i] = x[(tmp * (i + 1)) / 5];
		push_smaller_than_mpn(stacks, chunks[i]);
		i++;
	}
	if (stacks->len_a >= 2 && stacks->a[0] > stacks->a[1])
	{
		sab(stacks->a);
		ft_printf("sa\n");
	}
	push_by_chunks(stacks, chunks, i - 1, x[0]);
	free(x);
	t = -1;
	while (++t < stacks->len_a)
		ft_printf("a = %d\n", stacks->a[t]);
	ft_printf("\n");
	t = -1;
	while (++t < stacks->len_b)
		ft_printf("b = %d\n", stacks->b[t]);
	ft_printf("\n");
}*/