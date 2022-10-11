#include "push_swap.h"

void	algo_three(t_list *list_a)
{
	int	three_index[3];
	int	i;

	i = -1;
	while (list_a && ++i < 3)
	{
		three_index[i] = list_a->content->index;
		list_a = list_a->next;
	}
	if (three_index[0] > three_index[1] && three_index[0] > three_index[2])
	{
		rab(list_a);
		ft_printf("ra\n");
		if (three_index[0] > three_index[1])
			return (sab(list_a), ft_printf("sa\n"));
	}
	else if (three_index[1] > three_index[0] && three_index[1] > three_index[2])
	{
		rrab(list_a);
		ft_printf("rra\n");
		if (three_index[0] > three_index[1])
			return (sab(list_a), ft_printf("sa\n"));
	}
	else if (three_index[0] > three_index[1])
		return (sab(list_a), ft_printf("sa\n"));
	return ;
}

void	tri_positionel(t_list *list_a, t_list *list_b, int len)
{
	int	i;

	i = -1;
	len -= 3;
	while(++i < len)
	{
		pab(list_a,list_b);
		ft_printf("pb\n");
	}
	algo_three(list_a);
	i = len;
	while (i)
	{

	}
}