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

static void	place_pivot(int *a, int len_a)
{
	int	i;
	int	j;
	int pivot_num;
	int	tmp;
	int tmp2;

	i = 0;
 	while (a && a[i] && !num_max(a[i], a))
		i++;
	pivot_num = a[i] / 2;
	i = 0;
	while (a && a[i] && pivot_num != a[i])
		i++;
	if (a[i] && pivot_num == a[i])
	{
		if (i <= len_a / 2)
			exec(&rab, a, i, 0);
		else if (i > len_a / 2)
			exec(&rrab, a, i, 1);
		return ;
	}
	i = 0;
	tmp = pivot_num;
	while (a && a[i] && tmp != a[i])
	{
		i++;
		if (i > len_a - 1)
		{
			i = 0;
			tmp++;
		}
	}
	j = 0;
	tmp2 = pivot_num;
	while (a && a[i] && tmp2 != a[i])
	{
		i++;
		if (i > len_a - 1)
		{
			i = 0;
			tmp2--;
		}
	}
	if (tmp - pivot_num < pivot_num - tmp2)
	{
		if (i <= len_a / 2)
			exec(&rab, a, i, 0);
		else if (i > len_a / 2)
			exec(&rrab, a, i, 1);
		return ;
	}
	else
	{
		if (j <= len_a / 2)
			exec(&rab, a, j, 0);
		else if (j > len_a / 2)
			exec(&rrab, a, j, 1);
		return ;
	}
}

void	super_algo_op(int *a, int *b, int ac)
{
	int	len_a;
	int	len_b;
	int	i;
	int	tmp;
	int	pivot;

	len_a = ac - 1;
	len_b = 0;
	place_pivot(a, len_a); //put the pivot at the top
	pivot = 0;
	i = 1;
	while (1)
	{
		while (a[i] && a[i] < a[pivot])
			i++;
		if (a[i] && a[i] > a[pivot])
		{
			while (i > 1)
			{
				sab(a);
				ft_printf("sa\n");
				pivot++;
				rab(a);
				ft_printf("ra\n");
				i--;
				pivot--;
			}
			if (i == 1)
			{
				sab(a);
				ft_printf("sa\n");
				pab(b, a);
				ft_printf("pb\n");
				len_a--;
				len_b++;
				pivot = 0;
				i = 1;
			}
		}
		else
			break;
	}
	tmp = 0;
	while (tmp < len_a)
		ft_printf("%d\n", a[tmp++]);
	ft_printf("\n");
	tmp = 0;
	while (tmp < len_b)
		ft_printf("%d\n", b[tmp++]);
}
/*
	Pas si super que ca l'algo.
*/