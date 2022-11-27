/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_doing_things.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:18 by nmouslim          #+#    #+#             */
/*   Updated: 2022/11/27 13:51:51 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dying(t_philosophers **philosopher)
{
	if ((*philosopher)->data->philo_stop)
		return (1);
	if (current_time() - (*philosopher)->last_eaten >= \
		(*philosopher)->data->time_to_die)
		return (print_lock(philosopher, "died"), \
				(*philosopher)->data->philo_stop++, 1);
	return (0);
}

void	lock_fork(t_philosophers **philosopher)
{
	pthread_mutex_lock(&(*philosopher)->data->forks[\
		(*philosopher)->philo_nbr - 1]);
	print_lock(philosopher, "has taken a fork");
	if ((*philosopher)->philo_nbr == \
			(*philosopher)->data->number_of_philosophers)
		pthread_mutex_lock(&(*philosopher)->data->forks[0]);
	else
		pthread_mutex_lock(&(*philosopher)->data->forks[\
			(*philosopher)->philo_nbr]);
	print_lock(philosopher, "has taken a fork");
}

void	unlock_fork(t_philosophers **philosopher)
{
	pthread_mutex_unlock(&(*philosopher)->data->forks[\
		(*philosopher)->philo_nbr - 1]);
	if ((*philosopher)->philo_nbr == \
			(*philosopher)->data->number_of_philosophers)
		pthread_mutex_unlock(&(*philosopher)->data->forks[0]);
	else
		pthread_mutex_unlock(&(*philosopher)->data->forks[\
			(*philosopher)->philo_nbr]);
}

void	eating(t_philosophers **philosopher)
{
	if (!dying(philosopher))
	{
		lock_fork(philosopher);
		print_lock(philosopher, "is eating");
		(*philosopher)->last_eaten = current_time();
		if ((*philosopher)->data->time_to_eat > \
				(*philosopher)->data->time_to_die)
			usleep(((*philosopher)->data->time_to_die + 1) * 1000);
		else
			usleep((*philosopher)->data->time_to_eat * 1000);
		if ((*philosopher)->data->nbr_of_times_a_philo_must_eat >= 0)
			(*philosopher)->nbr_of_times_a_philo_has_eaten++;
		unlock_fork(philosopher);
	}
}
