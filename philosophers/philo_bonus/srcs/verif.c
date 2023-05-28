/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:59:39 by nmouslim          #+#    #+#             */
/*   Updated: 2023/05/27 15:59:40 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_lib.h"

static int	invalid_arg(char *arg)
{
	int	i;

	i = -1;
	while (arg && arg[++i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
	}
	return (0);
}

int	verif(int argc, char **argv)
{
	long int	number;
	int			i;

	if (argc < 5 || argc > 6)
		return (1);
	if (!argv[1])
		return (1);
	i = 0;
	while (++i < argc)
	{
		if (invalid_arg(argv[i]))
			return (1);
		number = ft_atoi(argv[i]);
		if ((i == 2 && number == 0) || number > INT_MAX || number < 0)
			return (1);
	}
	return (0);
}
