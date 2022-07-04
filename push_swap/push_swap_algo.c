/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:05:53 by nmouslim          #+#    #+#             */
/*   Updated: 2022/07/04 19:05:55 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_op(int *a, int *b, int ac)
{
	int	len_a;
	int	len_b;

	len_a = ac - 1;
	len_b = 0;
	while (1)
	{
		if (nums_in_order(a, len_b, 1, 1))
			break ;
		if (a[0] > a[1] && b[0] < b[1] && len_b > 1 && len_a > 1)
		{
			ss(a, b);
			ft_printf("ss\n");
		}
		else if (len_a > 1 && a[0] > a[1])
		{
			sab(a);
			ft_printf("sa\n");
		}
		else if (len_b > 1 && b[0] < b[1])
		{
			sab(b);
			ft_printf("sb\n");
		}
		else if (len_b >= 1 && b[0] < b[1] && (nums_in_order(a, len_b, 0, 1) && \
			nums_in_order(b, len_b, 0, 0)) || (nums_in_order(a, len_b, 0, 1) && \
			num_max(b[0], b)))
		{
			pab(a, b);
			len_a++;
			len_b--;
			ft_printf("pa\n");
		}
		else if (len_a >= 1 && a[0] < a[1] && !nums_in_order(a, len_b, 0, 1))
		{
			pab(b, a);
			len_b++;
			len_a--;
			ft_printf("pb\n");
		}
		/*else if (len_a > 2 && num_max(a[0], a) && len_b > 2 && num_min(b[0], b)\
			 && !nums_in_order(a, len_b, 0, 1) && !nums_in_order(b , len_b, 0, 0))
		{
			rr(a, b);
			ft_printf("rr\n");
		}
		else if (len_a > 2 && num_max(a[0], a) && !nums_in_order(a, len_b, 0, 1))
		{
			rab(a);
			ft_printf("ra\n");
		}
		else if (len_b > 2 && num_min(b[0], b) && !nums_in_order(b , len_b, 0, 0))
		{
			rab(b);
			ft_printf("rb\n");
		}
		else if (len_a > 2 && num_min_r(a[len_a], a) && len_b > 2 && \
			num_max_r(b[len_b], b)  && !nums_in_order(a, len_b, 0, 1) && \
			!nums_in_order(b , len_b, 0, 0))
		{
			rrr(a, b);
			ft_printf("rrr\n");
		}
		else if (len_a > 2 && num_min_r(a[len_a], a) && !nums_in_order(a, len_b, 0, \
			1))
		{
			rrab(a);
			ft_printf("rra\n");
		}
		else if (len_b > 2 && num_max_r(b[len_b], b) && !nums_in_order(b , len_b, 0, \
			0))
		{
			rrab(b);
			ft_printf("rrb\n");
		}*/
		else if (len_a > 2 && a[0] < a[len_a] && len_b > 2 && b[0] > b[len_b])
		{
			rr(a, b);
			ft_printf("rr\n");
		}
		else if (len_a > 2 && a[0] < a[len_a])
		{
			rab(a);
			ft_printf("ra\n");
		}
		else if (len_b > 2 && b[0] > b[len_b])
		{
			rab(b);
			ft_printf("rb\n");
		}
		else if (len_a > 2 && a[0] > a[len_a] && len_b > 2 && b[0] < b[len_b])
		{
			rrr(a, b);
			ft_printf("rrr\n");
		}
		else if (len_a > 2 && a[0] > a[len_a])
		{
			rrab(a);
			ft_printf("rra\n");
		}
		else if (len_b > 2 && b[0] < b[len_b])
		{
			rrab(b);
			ft_printf("rrb\n");
		}
		/*printf("\n\nlen_a = %d\n", len_a);
		printf("len_b = %d\n\n", len_b);
		printf("1 = %d\n", nums_in_order(a, len_b, 0, 1));
		printf("1 = %d\n\n", nums_in_order(b, len_b, 0, 0));*/
		/*ft_printf("\n%d  %d\n", a[0], b[0]);
		ft_printf("%d  %d\n", a[1], b[1]);
		ft_printf("%d  %d\n", a[2], b[2]);
		ft_printf("%d  %d\n", a[3], b[3]);
		ft_printf("%d  %d\n", a[4], b[4]);
		ft_printf("%d  %d\n", a[5], b[5]);
		ft_printf("%d  %d\n", a[6], b[6]);
		ft_printf("%d  %d\n", a[7], b[7]);
		ft_printf("%d  %d\n", a[8], b[8]);
		ft_printf("%d  %d\n", a[9], b[9]);*/
	}
}

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
