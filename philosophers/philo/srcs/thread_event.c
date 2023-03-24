/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:26:51 by nmouslim          #+#    #+#             */
/*   Updated: 2023/03/19 16:26:53 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	dying(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->infos);
	if (data->philo_stop < data->number_of_philosophers)
	{
		pthread_mutex_lock(&data->print);
		printf("%ld %d %s\n", current_time() - data->time, \
		philo->philo_nbr, DIE);
		pthread_mutex_unlock(&data->print);
		data->philo_stop = data->number_of_philosophers;
		pthread_mutex_unlock(&data->infos);
		return (1);
	}
	pthread_mutex_unlock(&data->infos);
	return (0);
}

static void	lock_fork(t_philo *philo, t_data *data)
{
	if (philo->philo_nbr % 2 > 0)
	{
		if (data->number_of_philosophers == 1)
			return (print_lock(philo, data, FORK), (void)usleep((data->time_to_die - (current_time() - philo->last_eaten)) * 1000));
		pthread_mutex_lock(data->forks + (philo->philo_nbr - 1));
		pthread_mutex_lock(data->forks + philo->philo_nbr % data->number_of_philosophers);
		print_lock(philo, data, FORK);
		print_lock(philo, data, FORK);
	}
	else
	{
		pthread_mutex_lock(data->forks + philo->philo_nbr % data->number_of_philosophers);
		pthread_mutex_lock(data->forks + (philo->philo_nbr - 1));
		print_lock(philo, data, FORK);
		print_lock(philo, data, FORK);
	}
}

static void	unlock_fork(t_philo *philo, t_data *data)
{
	if (philo->philo_nbr % 2 == 0)
	{
		pthread_mutex_unlock(data->forks + (philo->philo_nbr - 1));
		pthread_mutex_unlock(data->forks + philo->philo_nbr % data->number_of_philosophers);
	}
	else
	{
		pthread_mutex_unlock(data->forks + philo->philo_nbr % data->number_of_philosophers);
		pthread_mutex_unlock(data->forks + (philo->philo_nbr - 1));
	}
}

int	eating(t_philo *philo, t_data *data)
{
	lock_fork(philo, data);
	if (data->number_of_philosophers == 1)
		return (dying(philo, data));
	print_lock(philo, data, EAT);
	philo->last_eaten = current_time();
	if (ft_usleep(philo, data, data->time_to_eat))
		return (unlock_fork(philo, data), 1);
	if (data->nbr_of_times_a_philo_must_eat >= 0)
		philo->nbr_of_times_a_philo_has_eaten++;
	unlock_fork(philo, data);
	return (0);
}