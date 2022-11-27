/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:44 by nmouslim          #+#    #+#             */
/*   Updated: 2022/11/27 14:36:52 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time. tv_usec / 1000);
}

void	print_lock(t_philosophers *philo, char *current_activity)
{
	pthread_mutex_lock(&philo->data->print);
	if (!philo->data->philo_stop)
		printf("%ld %d %s\n", current_time() - philo->data->time, \
				philo->philo_nbr, current_activity);
	pthread_mutex_unlock(&philo->data->print);
}
