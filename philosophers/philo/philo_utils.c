/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:44 by nmouslim          #+#    #+#             */
/*   Updated: 2022/11/26 14:12:46 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time. tv_usec / 1000);
}

void	print_lock(t_philosophers **philosopher, char *current_activity)
{
	pthread_mutex_lock(&(*philosopher)->data->print);
	if (!(*philosopher)->data->philo_stop)
		printf("%ld %d %s\n", current_time() - (*philosopher)->data->time, \
				(*philosopher)->philo_nbr, current_activity);
	pthread_mutex_unlock(&(*philosopher)->data->print);
}
