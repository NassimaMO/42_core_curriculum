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

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			i;
	static int	*a;
	static int	*b;

	i = 0;
	if (!number_checker(argv, argc))
	{
		ft_putstr_fd("Error\n", 2);
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
	if (stacks.len_a <= 10)
		algo_op(&stacks);
	else if (stacks.len_a <= 200)
		twilio_algo(&stacks);
	else
		ayo_algo(&stacks);
	/*i = -1;
	while (++i < stacks.len_a)
		ft_printf("a = %d\n", stacks.a[i]);
	ft_printf("\n");
	i = -1;
	while (++i < stacks.len_b)
		ft_printf("b = %d\n", stacks.b[i]);
	ft_printf("\n");*/
	free(a);
	free(b);
	return (0);
}
