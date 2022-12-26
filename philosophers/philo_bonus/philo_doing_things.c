/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_doing_things.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:18 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/26 15:38:43 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dying(t_philosophers *philo)
{
	if (philo->data->number_of_philosophers == 1)
		usleep(philo->data->time_to_die * 1000);
	if (current_time() - philo->last_eaten >= philo->data->time_to_die)
	{
		print_lock(philo, "died");
		sem_wait(philo->data->print);
		/*printf("%ld %d %s\n", current_time() - philo->data->time, \
		philo->philo_nbr, "died");*/
		int	i = -1;
		usleep(1);
		/*while (++i < philo->data->number_of_philosophers)
			printf("%d.\n", philo->data->pid[i]);
		i = -1;*/
		while (++i < philo->data->number_of_philosophers)
		{
			if (i != philo->philo_nbr - 1)
				kill(philo->data->pid[i], SIGTERM);
		}
		kill(philo->data->pid[philo->philo_nbr - 1], SIGTERM);
		sem_post(philo->data->print);
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
