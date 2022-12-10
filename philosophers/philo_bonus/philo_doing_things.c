/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_doing_things.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:18 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/10 10:00:05 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dying(t_philosophers *philo)
{
	if (philo->data->philo_stop)
		return (1);
	if (philo->data->number_of_philosophers == 1)
		usleep(philo->data->time_to_die * 1000);
	if (current_time() - philo->last_eaten >= philo->data->time_to_die)
		return (print_lock(philo, "died"), philo->data->philo_stop++, kill(getpid(), SIGCHLD), 1);
	return (0);
}

int	lock_fork(t_philosophers *philo)
{
	int	i;
	int	test;

	i = -1;
	while (++i < philo->data->number_of_philosophers)
	{
		if (sem_getvalue(&philo->data->forks[i], &test) > 0)
		{
			sem_wait(&philo->data->forks[i]);
			break ;
		}
	}
	print_lock(philo, "has taken a fork");
	return (i);
}

void	unlock_fork(t_philosophers *philo, int n)
{
	int	i;

	i = -1;
	while (++i < philo->data->number_of_philosophers)
	{
		if (i == n)
			return ((void)sem_post(&philo->data->forks[philo->philo_nbr - 1]));
	}
}

void	eating(t_philosophers *philo)
{
	int	n;
	int	f;
	
	if (!dying(philo))
	{
		n = lock_fork(philo);
		f = lock_fork(philo);
		print_lock(philo, "is eating");
		ft_usleep(philo, philo->data->time_to_eat);
		philo->last_eaten = current_time();
		if (philo->data->nbr_of_times_a_philo_must_eat >= 0)
			philo->nbr_of_times_a_philo_has_eaten++;
		unlock_fork(philo, n);
		unlock_fork(philo, f);
	}
}
