#include "push_swap.h"

/*static void	exec(void (funct)(int *), int *a, int i, int x)
{
	if (!x)
	{
		while (a && a[i])
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
		funct(a);
	}
}

static void	exec_b(void (funct)(int *), int *b, int i, int x)
{
	if (!x)
	{
		while (b && b[i])
		{
			funct(b);
			ft_printf("rb\n");
			i--;
		}
	}
	else if (x)
	{
		while (b && b[i])
		{
			funct(b);
			i++;
			ft_printf("rrb\n");
		}
		funct(b);
	}
}

static void	order_b(int *a, int *b, int *len_b, int *len_a)
{
	int j;
	int	i;

	i = 0;
	while (!nums_in_order(b, *len_b, 0, 0))
	{
		while (b && b[i] && !num_max(b[i], b))
			i++;
		if (b && b[i] && i < *len_b / 2)
			exec_b(&rab, b, i, 0);
		else if (b && b[i] && i > *len_b / 2)
			exec_b(&rrab, b, i, 1);
		pab(a, b);
		(*len_a)--;
		(*len_b)++;
		ft_printf("pa\n");
		i = 0;
	}
}




void	super_algo_op(int *a, int *b, int ac)
{
	int	i;
	int	len_a;
	int	len_b;

	len_a = ac - 1;
	len_b = 0;
	i = -1;
	int	j;
	while (a && a[++i])
	{
		if (a[i] >= 0 && a[i] <= 19)
		{
			if (!num_min(a[i], a))
			{
				if (i < len_a / 2)
					exec(rab, a, i, 0);
				else if (i > len_a / 2)
					exec(rrab, a, i, 1);
			}
			if (nums_in_order(a, len_b, 1, 1))
				exit(0);
			pab(b, a);
			len_a--;
			len_b++;
			ft_printf("pb\n");
			i = -1;
		}
	}
	order_b(a, b, &len_b, &len_a);	

	i = -1;
	while (a && a[++i])
	{
		if (a[i] >= 20 && a[i] <= 39)
		{
			if (!num_min(a[i], a))
			{
				if (i < len_a / 2)
					exec(&rab, a, i, 0);
				else if (i > len_a / 2)
					exec(&rrab, a, i, 1);
			}
			if (nums_in_order(a, len_b, 1, 1))
				exit(0);
			pab(b, a);
			len_a--;
			len_b++;
			ft_printf("pb\n");
			i = -1;
		}
	}

	order_b(a, b, &len_b, &len_a);	

	i = -1;
	while (a && a[++i])
	{
		if (a[i] >= 40 && a[i] <= 59)
		{
			if (!num_min(a[i], a))
			{
				if (i < len_a / 2)
					exec(&rab, a, i, 0);
				else if (i > len_a / 2)
					exec(&rrab, a, i, 1);
			}
			if (nums_in_order(a, len_b, 1, 1))
				exit(0);
			pab(b, a);
			len_a--;
			len_b++;
			ft_printf("pb\n");
			i = -1;
		}
	}

	order_b(a, b, &len_b, &len_a);	

	i = -1;
	while (a && a[++i])
	{
		if (a[i] >= 60 && a[i] <= 79)
		{
			if (!num_min(a[i], a))
			{
				if (i < len_a / 2)
					exec(&rab, a, i, 0);
				else if (i > len_a / 2)
					exec(&rrab, a, i, 1);
			}
			if (nums_in_order(a, len_b, 1, 1))
				exit(0);
			pab(b, a);
			len_a--;
			len_b++;
			ft_printf("pb\n");
			i = -1;
		}
	}

	order_b(a, b, &len_b, &len_a);	

	i = -1;
	while (a && a[++i])
	{
		if (a[i] >= 80 && a[i] <= 100)
		{
			if (!num_min(a[i], a))
			{
				if (i < len_a / 2)
					exec(&rab, a, i, 0);
				else if (i > len_a / 2)
					exec(&rrab, a, i, 1);
			}
			if (nums_in_order(a, len_b, 1, 1))
				exit(0);
			pab(b, a);
			len_a--;
			len_b++;
			ft_printf("pb\n");
			i = -1;
		}
	}

	order_b(a, b, &len_b, &len_a);	
	
	i = 0;
	while (len_b)
	{
		pab(a, b);
		len_a++;
		len_b--;
		ft_printf("pa\n");
	}
}*/


/*static void	commands_the_first(int *a, int *b, int *len_a, int *len_b)
{
	if (*len_a > 2 && num_min_r(a[*len_a - 1], a))
	{
		rrab(a);
		ft_printf("rra\n");
	}
	else if (*len_b >= 2 && !num_max(b[0], b))
	{
		rab(b);
		ft_printf("rb\n");
		return ;
	}
	else if (*len_b > 2 && num_min_r(b[0], b))
	{
		rrab(b);
		ft_printf("rrb\n");
	}
	else if (*len_a >= 2 && (a[0] > a[*len_a - 1] || a[0] > a[1]) && !num_min(a[0], a))
	{
		rab(a);
		ft_printf("ra\n");
		return ;
	}
	else if (*len_a > 2 && !nums_in_order(a, *len_b, 0, 1) && !(*len_a == 3 && a[0] > a[1]))
	{
		pab(b, a);
		(*len_b)++;
		(*len_a)--;
		ft_printf("pb\n");
		return ;
	}
	else if (*len_b >= 1 && nums_in_order(a, *len_b, 0, 1))
	{
		pab(a, b);
		(*len_a)++;
		(*len_b)--;
		ft_printf("pa\n");
		return ;
	}
}

void	super_algo_op(int *a, int *b, int ac)
{
	int	len_a;
	int	len_b;
	int	i;

	len_a = ac - 1;
	len_b = 0;
	i = 0;
	while (1)
	{
		if (nums_in_order(a, len_b, 1, 1))
			break ;
		if ((len_b >= 2 && !num_max(b[0], b)) && (len_a >= 2 && (a[0] > a[len_a - 1] || a[0] > a[1]) && !num_min(a[0], a)))
		{
			rr(a, b);
			ft_printf("rr\n");
		}
		else if (len_a > 2 && len_b > 2 && num_min_r(a[len_a - 1], a) && num_min_r(b[0], b))
		{
			rrr(a, b);
			ft_printf("rrr\n");
		}
		else
			commands_the_first(a, b, &len_a, &len_b);
		ft_printf("\nla = %d\n", len_a);
		while (a && a[i])
		{
			printf("\na = %d", a[i]);
			i++;
		}
		printf("\n");
		i = 0;
		ft_printf("\nlb = %d\n", len_b);
		while (b && b[i])
		{
			printf("\nb = %d", b[i]);
			i++;
		}
		printf("\n");
		i = 0;
	}
}*/

/*
	Pas si super que ca l'algo.
*/