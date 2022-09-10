/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:06:12 by nmouslim          #+#    #+#             */
/*   Updated: 2022/07/04 19:06:13 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_putstrtest_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			i;
	static int	*a;
	static int	*b;

	i = 0;
	if (!number_checker(argv, argc))
	{
		ft_putstrtest_fd("Error\n", 2);
		exit(1);
	}
	if (argc <= 2)
		return (0);
	a = put_int_tab(argv, argc);
	if (!a)
		return (1);
	b = malloc(sizeof(int) * argc);
	if (!b)
	{
		free(a);
		return (1);
	}
	while (i < argc)
		b[i++] = '\0';
	stacks.len_a = argc - 1;
	stacks.len_b = 0;
	stacks.a = a;
	stacks.b = b;
	if (nums_in_order_rev(stacks.a, stacks.len_a))
	{
		rev_scase(&stacks);
		return (0);
	}
	if (stacks.len_a <= 25)
		algo_op(&stacks);
	else if (stacks.len_a <= 200)
		super_algo_op3(&stacks);
	else
		super_algo_op3(&stacks);
	free(a);
	free(b);
	return (0);
}
