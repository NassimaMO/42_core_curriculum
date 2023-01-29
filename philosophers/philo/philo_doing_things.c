/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_doing_things.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:18 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/23 18:07:17 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/types.h>

int	dying(t_philosophers *philo)
{
	if (philo->data->philo_stop >= philo->data->number_of_philosophers)
		return (1);
	if (philo->data->number_of_philosophers == 1)
		usleep(philo->data->time_to_die * 1000);
	if (current_time() - philo->last_eaten >= philo->data->time_to_die)
		return (print_lock(philo, "died"), philo->data->philo_stop=philo->data->number_of_philosophers, 1);
	return (0);
}

void	lock_fork(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->philo_nbr - 1]);
	print_lock(philo, "has taken a fork");
	if (philo->philo_nbr == philo->data->number_of_philosophers)
		pthread_mutex_lock(&philo->data->forks[0]);
	else
		pthread_mutex_lock(&philo->data->forks[philo->philo_nbr]);
	print_lock(philo, "has taken a fork");
}

void	unlock_fork(t_philosophers *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->philo_nbr - 1]);
	if (philo->philo_nbr == philo->data->number_of_philosophers)
		pthread_mutex_unlock(&philo->data->forks[0]);
	else
		pthread_mutex_unlock(&philo->data->forks[philo->philo_nbr]);
}

void	eating(t_philosophers *philo)
{
	if (!dying(philo))
	{
		lock_fork(philo);
		print_lock(philo, "is eating");
		ft_usleep(philo, philo->data->time_to_eat);
		philo->last_eaten = current_time();
		if (philo->data->nbr_of_times_a_philo_must_eat >= 0)
			philo->nbr_of_times_a_philo_has_eaten++;
		unlock_fork(philo);
	}
}
