/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_doing_things.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:18 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/17 16:03:37 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dying(t_philosophers *philo)
{
	int	i;

	i = -1;
	if (philo->data->forks[philo->philo_nbr - 1].__align < 0)
		return (1);
	if (philo->data->number_of_philosophers == 1)
		usleep(philo->data->time_to_die * 1000);
	if (current_time() - philo->last_eaten >= philo->data->time_to_die)
	{
		print_lock(philo, "died");
		while (++i < philo->data->number_of_philosophers)
			philo->data->forks[i].__align = -1;
		return (1);
	}
	return (0);
}

int	lock_fork(t_philosophers *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->number_of_philosophers)
	{
		sem_wait(&philo->data->print);
		printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||i=%d, align=%ld.\n", i, philo->data->forks[i].__align);
		sem_post(&philo->data->print);
		if (philo->data->forks[i].__align == 0)
		{
			philo->data->forks[i].__align++;
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
		{
			sem_post(&philo->data->forks[philo->philo_nbr - 1]);
			philo->data->forks[i].__align = 0;
			return ;
		}
	}
}

void	eating(t_philosophers *philo)
{
	int	m;
	int	f;
	
	if (!dying(philo))
	{
		m = lock_fork(philo);
		f = lock_fork(philo);
		print_lock(philo, "is eating");
		ft_usleep(philo, philo->data->time_to_eat);
		philo->last_eaten = current_time();
		if (philo->data->nbr_of_times_a_philo_must_eat >= 0)
			philo->nbr_of_times_a_philo_has_eaten++;
		unlock_fork(philo, m);
		unlock_fork(philo, f);
	}
}
