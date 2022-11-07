/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:44:51 by nmouslim          #+#    #+#             */
/*   Updated: 2022/11/07 13:54:42 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	nums_in_order(int *a, int len_a, int len_b)
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

static int	go_through_other_instructions(char *instruct, \
	t_data_stacks *stacks, int len)
{
	if (!ft_strncmp(instruct, "rrb\n", len) && len == 4 && stacks->len_b > 1)
		rrab(stacks->b, stacks->len_b);
	else if (!ft_strncmp(instruct, "sb\n", len) && len == 3 && stacks->len_b > 1)
		sab(stacks->b);
	else if (!ft_strncmp(instruct, "pa\n", len) && len == 3 && stacks->len_b > 0)
	{
		pab(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
		(stacks->len_a)++;
		(stacks->len_b)--;
	}
	else if (!ft_strncmp(instruct, "pb\n", len) && len == 3 && stacks->len_a > 0)
	{
		pab(stacks->b, stacks->a, stacks->len_b, stacks->len_a);
		(stacks->len_a)--;
		(stacks->len_b)++;
	}
	else
		return (free(stacks->b), ft_printf("Error\n"), 1);
	return (0);
}

static int	go_through_instructions(char *instruct, t_data_stacks *stacks)
{
	int	len;

	len = ft_strlen(instruct);
	if (!ft_strncmp(instruct, "rr\n", len) && len == 3 && stacks->len_a > 1 && \
		stacks->len_b > 1)
		rr(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
	else if (!ft_strncmp(instruct, "rrr\n", len) && len == 4 && \
		stacks->len_a > 1 && stacks->len_b > 1)
		rrr(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
	else if (!ft_strncmp(instruct, "ss\n", len) && len == 3 && \
		stacks->len_a > 1 && stacks->len_b > 1)
		ss(stacks->a, stacks->b);
	else if (!ft_strncmp(instruct, "ra\n", len) && len == 3 && stacks->len_a > 1)
		rab(stacks->a, stacks->len_a);
	else if (!ft_strncmp(instruct, "rra\n", len) && len == 4 && \
		stacks->len_a > 1)
		rrab(stacks->a, stacks->len_a);
	else if (!ft_strncmp(instruct, "sa\n", len) && len == 3 && stacks->len_a > 1)
		sab(stacks->a);
	else if (!ft_strncmp(instruct, "rb\n", len) && len == 3 && stacks->len_b > 1)
		rab(stacks->b, stacks->len_b);
	else
		if (go_through_other_instructions(instruct, stacks, len))
			return (1);
	return (0);
}

int	execute_instruct(char **tab, int len_tab, int *a, int len_a)
{
	int				i;
	t_data_stacks	stacks;

	i = 0;
	stacks.len_a = len_a;
	stacks.a = a;
	stacks.len_b = 0;
	stacks.b = malloc(sizeof(int) * stacks.len_a + 1);
	if (!stacks.b)
		return (free(a), 1);
	ft_bzero(stacks.b, sizeof(int));
	while (i < len_tab && tab[i])
	{
		if (go_through_instructions(tab[i], &stacks))
			return (0);
		i++;
	}
	if (nums_in_order(stacks.a, stacks.len_a, stacks.len_b))
		return (free(stacks.b), ft_printf("OK\n"), 1);
	return (free(stacks.b), ft_printf("KO\n"), 0);
}
