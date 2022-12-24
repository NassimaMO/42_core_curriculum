/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_doing_things.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:18 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/24 20:04:58 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dying(t_philosophers *philo)
{
	if (philo->data->philo_stop >= philo->data->number_of_philosophers)
		return (1);
	if (philo->data->number_of_philosophers == 1)
		usleep(philo->data->time_to_die * 1000);
	if (current_time() - philo->last_eaten >= philo->data->time_to_die)
	{
		print_lock(philo, "died");
		philo->data->philo_stop = philo->data->number_of_philosophers;
		kill(0, SIGTERM);
		return (1);
	}
	return (0);
}

void	lock_fork(t_philosophers *philo)
{
	sem_wait(philo->data->forks);
	print_lock(philo, "has taken a fork");
}

void	unlock_fork(t_philosophers *philo)
{
	sem_post(philo->data->forks);
}

void	eating(t_philosophers *philo)
{
	if (!dying(philo))
	{
		lock_fork(philo);
		lock_fork(philo);
		print_lock(philo, "is eating");
		ft_usleep(philo, philo->data->time_to_eat);
		philo->last_eaten = current_time();
		if (philo->data->nbr_of_times_a_philo_must_eat >= 0)
			philo->nbr_of_times_a_philo_has_eaten++;
		unlock_fork(philo);
		unlock_fork(philo);
	}
}
