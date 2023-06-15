/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:59:31 by nmouslim          #+#    #+#             */
/*   Updated: 2023/05/27 15:59:33 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_lib.h"

long int	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time. tv_usec / 1000);
}

int	ft_usleep(t_data *data, long int time_to_do_smth)
{
	long int	time;

	time = current_time();
	while (current_time() < time + time_to_do_smth)
	{
		if (dying(data))
			return (1);
	}
	return (0);
}

void	print_lock(t_data *data, char *current_activity)
{
	sem_wait(data->print_sem);
	sem_wait(data->stop_sem);
	if (!data->stop)
	{
		printf("%ld %d %s\n", current_time() - data->time, \
			data->philo_nbr, current_activity);
	}
	sem_post(data->stop_sem);
	sem_post(data->print_sem);
}

int	ft_atoi(const char *nptr)
{
	long int	result;
	int			minus;
	int			i;

	i = 0;
	result = 0;
	minus = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			minus = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result += nptr[i] - 48;
		if (nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
			result *= 10;
		i++;
	}
	return (result * minus);
}
