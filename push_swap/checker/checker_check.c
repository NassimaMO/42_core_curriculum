/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:44:51 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/19 13:47:37 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	nums_in_order(int *a, int len_a, int len_b)
{
	int	i;

	i = 1;
	if (len_b)
		return (0);
	while (i < len_a)
	{
		if (a[i] < a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	execute_instruct(char **tab, int len_tab, int *a, int len_a, int *b)
{
	int	i;
	int	len;
	int	len_b;

	len_b = 0;
	i = 0;
	while (i < len_tab && tab[i])
	{
		len = ft_strlen(tab[i]);
		if (!ft_strncmp(tab[i], "rr\n", len) && len == 3)
			rr(a, b, len_a, len_b);
		else if (!ft_strncmp(tab[i], "rrr\n", len) && len == 4)
			rrr(a, b, len_a, len_b);
		else if (!ft_strncmp(tab[i], "ss\n", len) && len == 3)
			ss(a, b);
		else if (!ft_strncmp(tab[i], "ra\n", len) && len == 3)
			rab(a, len_a);
		else if (!ft_strncmp(tab[i], "rra\n", len) && len == 4)
			rrab(a, len_a);
		else if (!ft_strncmp(tab[i], "sa\n", len) && len == 3)
			sab(a);
		else if (!ft_strncmp(tab[i], "rb\n", len) && len == 3)
			rab(b, len_b);
		else if (!ft_strncmp(tab[i], "rrb\n", len) && len == 4)
			rrab(b, len_b);
		else if (!ft_strncmp(tab[i], "sb\n", len) && len == 3)
			sab(b);
		else if (!ft_strncmp(tab[i], "pa\n", len) && len == 3)
		{
			pab(a, b, len_a, len_b);
			len_a++;
			len_b--;
		}
		else if (!ft_strncmp(tab[i], "pb\n", len) && len == 3)
		{
			pab(b, a, len_b, len_a);
			len_a--;
			len_b++;
		}
		else
			return (ft_printf("Error\n"), 0);
		i++;
	}
	if (nums_in_order(a, len_a, len_b))
		return (ft_printf("OK\n"), 1);
	return (ft_printf("KO\n"), 0);
}
