/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:44 by nmouslim          #+#    #+#             */
/*   Updated: 2023/02/05 16:24:44 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long int	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time. tv_usec / 1000);
}

void	ft_usleep(t_philosophers *philosopher, long int time_to_do_smth)
{
	long int	time;

	time = current_time();
	while (current_time() < time + time_to_do_smth)
	{
		pthread_mutex_lock(&philosopher->data->stop);
		if (philosopher->data->philo_stop >= \
			philosopher->data->number_of_philosophers || dying(philosopher))
		{
			pthread_mutex_unlock(&philosopher->data->stop);
			return ;
		}
		pthread_mutex_unlock(&philosopher->data->stop);
	}
}

void	print_lock(t_philosophers *philo, char *current_activity)
{
	pthread_mutex_lock(&philo->data->print);
	usleep(1);
	if (philo->data->philo_stop < philo->data->number_of_philosophers)
		printf("%ld %d %s\n", current_time() - philo->data->time, \
				philo->philo_nbr, current_activity);
	pthread_mutex_unlock(&philo->data->print);
}
