#include "push_swap.h"

int	*put_int_tab(char **argv, int argc)
{
	int	*a;
	int	i;
	int	j;

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

void	ft_sort_int_tab(int *tab, int size)
{
	int	copie;
	int	index;

	index = 0;
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
}