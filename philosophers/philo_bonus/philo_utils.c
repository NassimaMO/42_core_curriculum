/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:44 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/04 16:06:41 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		if (philosopher->data->philo_stop || dying(philosopher))
			return ;
	}
}

void	print_lock(t_philosophers *philo, char *current_activity)
{
	sem_wait(&philo->data->print);
	if (!philo->data->philo_stop)
		printf("%ld %d %s\n", current_time() - philo->data->time, \
				philo->philo_nbr, current_activity);
	sem_post(&philo->data->print);
}
