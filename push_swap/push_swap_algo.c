#include "push_swap.h"

void algo_op(int *a, int *b, int *len_a, int *len_b)
{
	if (a[0] > a[1] && b[0] < b[1] && *len_b > 1 && *len_a > 1)
	{
		ss(a, b);
		ft_printf("ss\n");
	}
	else if (*len_a > 1 && a[0] > a[1])
	{
		sab(a);
		ft_printf("sa\n");
	}
	else if (*len_b > 1 && b[0] < b[1])
	{
		sab(b);
		ft_printf("sb\n");
	}
	else if (*len_a >= 1 && a[0] < a[1])
	{
		pab(b, a);
		(*len_b)++;
		(*len_a)--;
		ft_printf("pb\n");
	}
	else if (*len_b >= 1 && b[0] > b[1])
	{
		pab(a, b);
		(*len_a)++;
		(*len_b)--;
		ft_printf("pa\n");
	}
	printf("len_a = %d\n", *len_a);
	printf("len_b = %d\n", *len_b);
	ft_printf("\n%d", a[0]);
	ft_printf("\n%d", a[1]);
	ft_printf("\n%d", a[2]);
	/*	else if (a)
			rab(a);
		else if (b)
			rab(b);
		else if (a && b)
			rr(a, b);

		else if (a)
			rrab(a);
		else if (b)
			rrab(b);
		else if (a && b)
			rrr(a, b);*/
}

/*
	while (index < size - 1)
	{
		if (tab[index + 1] < tab[index])
		{
			copie = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = copie;
			index = -1;
		}
		index++;
	}
*/

int nums_in_order(int *a, int len_b)
{
	int i;

	i = 1;
	if (len_b != 0)
		return (0);
	while (a[i])
	{
		if (a[i] < a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int *put_int_tab(char **argv, int argc)
{
	int *a;
	int i;
	int j;

	i = 1;
	j = 0;
	a = malloc(sizeof(int) * argc);
	if (!a)
		return (0);
	while (i < argc)
	{
		a[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	a[j] = '\0';
	return (a);
}