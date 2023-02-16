/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:55 by nmouslim          #+#    #+#             */
/*   Updated: 2023/02/16 18:00:26 by nmouslim         ###   ########.fr       */
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
			return (printf("Invalid arguments.\n"), 1);
		number = atoi(argv[i]);
		if ((i == 2 && number == 0) || number > INT_MAX || number < 0)
			return (printf("Invalid arguments.\n"), 1);
	}
	return (0);
}
