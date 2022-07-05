#include "checker.h"

int nums_in_order(int *a, int *b)
{
	int	i;

	i = 1;
	if (!b || !b[0])
		return (0);
	while (a[i])
	{
		if (a[i] < a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int execute_instruct(char **tab, int *a, int *b)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == "rr\n")
			rr(a, b);
		else if (tab[i] == "rrr\n")
			rrr(a, b);
		else if (tab[i] == "ss\n")
			ss(a, b);
		else if (tab[i] == "ra\n")
			rab(a);
		else if (tab[i] == "rra\n")
			rrab(a);
		else if (tab[i] == "sa\n")
			sab(a);
		else if (tab[i] == "rb\n")
			rab(b);
		else if (tab[i] == "rrb\n")
			rrab(b);
		else if (tab[i] == "sb\n")
			sab(b);
		else if (tab[i] == "pa\n")
			pab(a, b);
		else if (tab[i] == "pb\n")
			pab(b, a);
		i++;
	}
	if (nums_in_order(a, b))
			return (ft_printf("OK"), 1);
	return(ft_printf("KO"), 0);
}

char	**str_to_tab()
{
	char 	**tab;
	int		c;
	int		i;
	
	open(1, O_RDONLY);
	i = 0;
	tab = malloc(sizeof(char *) * /*taille tableau*/);
	while (tab[i] = get_next_line(1))
	{
		if (!tab[i])
			free_tab(tab, i);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}