#include "push_swap.h"

void	quick_sort(int *a, int first, int last);

void	super_algo_op(int *a, int *b, int ac)
{
	int	len_a;
	//int	len_b;
	int	i;
	int	j;
	

	len_a = ac - 1;
	//len_b = 0;
	i = 0;
	j = len_a - 1;
	(void)b;
	quick_sort(a, i, j);
	i = 0;
	while (i < len_a)
		ft_printf("%d\n", a[i++]);
}

void	quick_sort(int *a, int first, int last)
{
	int	i = first;
	int	j = last;
	int	pivot = last;
	int	tmp;

	if (first < last)
	{
		while (i < j)
		{
			while (a[i] <= a[pivot])
				i++;
			while (a[j] >= a[pivot])
				j--;
			if (i < j)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		tmp = a[pivot];
		i = pivot;
		while (a[i - 1] != a[j])
		{
			a[i] = a[i - 1];
			i--;
		}
		a[i] = tmp;
		quick_sort(a, first, j - 1);
		quick_sort(a, j + 1, last);
	}
}
/*
	Pas si super que ca l'algo.
*/