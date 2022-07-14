#include "push_swap.h"

void	super_algo_op(int *a, int *b, int ac)
{
	int	len_a;
	int	len_b;
	int	i;
	int	j;
	int	tmp;
	int	pivot;

	len_a = ac - 1;
	len_b = 0;
	pivot = len_a - 1;
	i = 0;
	j = len_a - 2;
	while (i < j)
	{
		while (a[i] < a[pivot])
			i++;
		while (a[j] > a[pivot])
			j--;
		if (i < j)
		{
			while (i > 1)
			{
				rab(a);
				ft_printf("ra\n");
				i--;
			}
			while (i != 0 && pivot != 1)
			{
				if (i == 1)
				{
					sab(a);
					ft_printf("sa\n");
					i--;
				}
				else
				{
					rrab(a);
					ft_printf("rra\n");
					i++;
				}
			}
			while (i != len_a - 2 && pivot != len_a - 1)
			{
				rab(a);
				ft_printf("ra\n");
				if (pivot == 0)
					pivot = len_a - 1;
				else
					pivot--;
				if (i == 0)
					i = len_a - 1;
				else
					i--;
			}

			/*tmp = 0;
			ft_printf("len = %d\n", len_a);
			while (tmp < len_a)
				ft_printf("%d\n", a[tmp++]);
			ft_printf("\n");*/
			/*tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;*/
		}
	}
	/*tmp = a[pivot];
	while (a[pivot - 1] != a[j])
	{
		a[pivot] = a[pivot - 1];
		pivot--;
	}
	a[pivot] = tmp;
	i = pivot;
	ft_printf("i = %d\n", i);*/
	/*while (i)
	{
		pab(b, a);
		len_b++;
		len_a--;
		ft_printf("pb\n");
		i--;
	}*/





































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