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

int	main(int argc, char **argv)
{
	int			i;
	static int	*a;
	static int	*b;

	i = 0;
	if (!number_checker(argv, argc))
		return (ft_printf("Error\n"), 0);
	if (argc <= 2)
		return (0);
	a = put_int_tab(argv, argc);
	if (!a)
		return (1);
	b = malloc(sizeof(int) * argc);
	if (!b)
		return (1);
	while (i <= argc)
		b[i++] = '\0';
	algo_op(a, b, argc);
	free(a);
	free(b);
	return (0);
}
