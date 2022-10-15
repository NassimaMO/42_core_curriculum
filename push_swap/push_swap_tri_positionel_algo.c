#include "push_swap.h"

int	algo_three(t_list **list_a)
{
	int	three_index[3];
	int	i;
	t_list *tmp;

	i = -1;
	tmp = *list_a;
	while (++i < 3)
		three_index[i] = 0;
	i = -1;
	while (tmp && ++i < 3)
	{
		three_index[i] = tmp->content->index;
		tmp = tmp->next;
	}
	if (three_index[0] > three_index[1] && three_index[0] > three_index[2])
	{
		rab(list_a);
		ft_printf("ra\n");
		if (three_index[1] > three_index[2])
			return (sab(list_a), ft_printf("sa\n"), 0);
	}
	else if (three_index[1] > three_index[0] && three_index[1] > three_index[2])
	{
		rrab(list_a);
		ft_printf("rra\n");
		if (three_index[2] > three_index[0])
			return (sab(list_a), ft_printf("sa\n"), 0);
	}
	else if (three_index[0] > three_index[1])
		return (sab(list_a), ft_printf("sa\n"), 0);
	return (0);
}

// to test
/*//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\\*/

static void	put_target_pos(t_list *b, t_list *a) 
{
	int	pos;
	int	biggest_index_case;
	int	save_index;
	int	save_index_bic;

	save_index = 2147483647;
	save_index_bic = 2147483647;
	while (a)
	{
		if (a->content->index > b->content->index && a->content->index < save_index)
		{
			pos = a->content->pos;
			save_index = a->content->index;
		}
		if (a->content->index < b->content->index && a->content->index < save_index_bic)
		{
			biggest_index_case = a->content->pos;
			save_index_bic = a->content->index;
		}
		a = a->next;
	}
	if (save_index == 2147483647)
		pos = biggest_index_case;
	b->content->target_pos = pos;
}

static void	get_target_pos(t_list **list_a, t_list **list_b)
{
	t_list *tmp_a;
	t_list *tmp_b;

	tmp_a = *list_a;
	tmp_b = *list_b;
	while (tmp_b)
	{
		put_target_pos(tmp_b, tmp_a);
		tmp_a = *list_a;
		tmp_b = tmp_b->next;
	}
}

/*/||||||||||||||||||||||||||||||||||||\*/

static int	get_lst_len(t_list **lst)
{
	int	i;
	t_list *tmp;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static int calculate_cost(int pos, int len)
{
	int	i;

	i = 0;
	if (pos > len / 2)
	{
		pos--;
		while (++pos < len)
			i--;
	}
	else
	{
		pos++;
		while (--pos > 0)
			i++;
	}
	return (i);
}

void	calculate_movements_costs(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;
	int	len_a;
	int	len_b;

	tmp = *list_b;
	len_b = get_lst_len(list_b);
	len_a = get_lst_len(list_a);
	while (tmp)
	{
		tmp->content->cost_b = calculate_cost(tmp->content->pos, len_b);
		tmp->content->cost_a = calculate_cost(tmp->content->target_pos, len_a);
		tmp = tmp->next;
	}
}

/*/||||||||||||||||||||||||||||||||||||\*/

int	get_total_cost(t_list *lst)
{
	int	a;
	int	b;

	a = lst->content->cost_a;
	b = lst->content->cost_b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}

void	perform_movement(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;
	int		min_cost;
	int		total_cost;
	int		cost_a;
	int		cost_b;

	tmp = *list_b;
	cost_a = 0;
	cost_b = 0;
	min_cost = 2147483647;
	while (tmp)
	{
		total_cost = get_total_cost(tmp);
		if (total_cost < min_cost)
		{
			cost_a = tmp->content->cost_a;
			cost_b = tmp->content->cost_b;
			min_cost = total_cost;
		}
		tmp = tmp->next;
	}
	while (cost_b < 0 && cost_a < 0)
	{
		rrr(list_a, list_b);
		ft_printf("rrr\n");
	}
	while (cost_b > 0 && cost_a > 0)
	{
		rr(list_a, list_b);
		ft_printf("rr\n");
	}
	while (cost_b < 0)
	{
		rrab(list_b);
		ft_printf("rrb\n");
		cost_b++;
	}
	while (cost_b > 0)
	{
		rab(list_b);
		ft_printf("rb\n");
		cost_b--;
	}
	while (cost_a < 0)
	{
		rrab(list_a);
		ft_printf("rra\n");
		cost_a++;
	}
	while (cost_a > 0)
	{
		rab(list_a);
		ft_printf("ra\n");
		cost_a--;
	}
}

/*/||||||||||||||||||||||||||||||||||||\*/

int	find_min_pos(t_list **list_a)
{
	t_list	*tmp;

	tmp = *list_a;
	while (tmp)
	{
		if (tmp->content->index == 0)
			return (tmp->content->pos);
		tmp = tmp->next;
	}
	return (0);
}

void	put_list_in_order(t_list **list_a, int len)
{
	int	pos;

	pos = find_min_pos(list_a);
	pos = calculate_cost(pos, len);
	while (pos < 0)
	{
		rrab(list_a);
		ft_printf("rra\n");
		pos++;
	}
	while (pos > 0)
	{
		rrab(list_a);
		ft_printf("ra\n");
		pos--;
	}
}

/*//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\\*/

void	tri_positionel(t_list **list_a, t_list **list_b, int len, int mediane)
{
	int	i;

	i = -1;
	while(++i < len - 3)
	{
		if (i < len / 2)
		{
			while ((*list_a)->content->value >= mediane)
			{
				rab(list_a);
				ft_printf("ra\n");
			}
			if (i == 0)
			{
				*list_b = malloc(sizeof(t_list));
				ft_bzero(list_b, sizeof(t_list));
			}
			pab(list_a, list_b);
			ft_printf("pb\n");
		}
		else
		{
			pab(list_a, list_b);
			ft_printf("pb\n");
		}
	}
	algo_three(list_a);
	i = len - 3;
	while (i)
	{
		get_target_pos(list_a, list_b);
		calculate_movements_costs(list_a, list_b);
		perform_movement(list_a, list_b);
		pab(list_b, list_a);
		ft_printf("pa\n");
		i--;
	}
	put_list_in_order(list_a, len);
}