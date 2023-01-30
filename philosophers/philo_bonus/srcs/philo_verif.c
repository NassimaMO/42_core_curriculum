/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:55 by nmouslim          #+#    #+#             */
/*   Updated: 2023/01/30 10:18:43 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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

int	arg_verif(int argc, char **argv)
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
		number = atoi(argv[i]);
		if (number > INT_MAX || number < 0)
			return (1);
	}
	return (0);
}
