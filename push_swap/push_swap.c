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
	if (argc - 1 <= 25)
		algo_op(a, b, argc);
	else if (argc - 1 <= 200)
		twilio_algo(a, b, argc);
	else
		super_algo_op3(a, b, argc);
	free(a);
	free(b);
	return (0);
}
