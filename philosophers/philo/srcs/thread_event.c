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
	if (data->philo_stop < data->nbr_philos)
	{
		pthread_mutex_lock(&data->print);
		printf("%ld %d %s\n", current_time() - data->time, \
		philo->philo_nbr, DIE);
		pthread_mutex_unlock(&data->print);
		data->philo_stop = data->nbr_philos;
		pthread_mutex_unlock(&data->infos);
		return (1);
	}
	pthread_mutex_unlock(&data->infos);
	return (0);
}

static void	lock_fork(t_philo *philo, t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->forks[philo->philo_nbr % data->nbr_philos + (philo->philo_nbr == data->nbr_philos) * (data->nbr_philos - 1)]);
		pthread_mutex_lock(&data->forks[(philo->philo_nbr - 1) * (philo->philo_nbr < data->nbr_philos)]);
		if (!data->tab_forks[philo->philo_nbr - 1] && !data->tab_forks[philo->philo_nbr % data->nbr_philos])
			break ;
		pthread_mutex_unlock(&data->forks[(philo->philo_nbr - 1) * (philo->philo_nbr < data->nbr_philos)]);
		pthread_mutex_unlock(&data->forks[philo->philo_nbr % data->nbr_philos + (philo->philo_nbr == data->nbr_philos) * (data->nbr_philos - 1)]);
		ft_usleep(philo, data, 1);
	}
	data->tab_forks[philo->philo_nbr - 1] = 1;
	data->tab_forks[philo->philo_nbr % data->nbr_philos] = 1;
	pthread_mutex_unlock(&data->forks[(philo->philo_nbr - 1) * (philo->philo_nbr < data->nbr_philos)]);
	pthread_mutex_unlock(&data->forks[philo->philo_nbr % data->nbr_philos + (philo->philo_nbr == data->nbr_philos) * (data->nbr_philos - 1)]);
	print_lock(philo, data, FORK);
	print_lock(philo, data, FORK);
}

static void	unlock_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->philo_nbr % data->nbr_philos + (philo->philo_nbr == data->nbr_philos) * (data->nbr_philos - 1)]);
	pthread_mutex_lock(&data->forks[(philo->philo_nbr - 1) * (philo->philo_nbr < data->nbr_philos)]);
	data->tab_forks[philo->philo_nbr - 1] = 0;
	data->tab_forks[philo->philo_nbr % data->nbr_philos] = 0;
	pthread_mutex_unlock(&data->forks[(philo->philo_nbr - 1) * (philo->philo_nbr < data->nbr_philos)]);
	pthread_mutex_unlock(&data->forks[philo->philo_nbr % data->nbr_philos + (philo->philo_nbr == data->nbr_philos) * (data->nbr_philos - 1)]);
}

int	eating(t_philo *philo, t_data *data)
{
	if (data->nbr_philos == 1 && (print_lock(philo, data, FORK), usleep(1000 * (data->time_to_die - (current_time() - data->time))), 1))
		return (dying(philo, data));
	lock_fork(philo, data);
	print_lock(philo, data, EAT);
	philo->last_eaten = current_time();
	if (ft_usleep(philo, data, data->time_to_eat))
		return (unlock_fork(philo, data), 1);
	unlock_fork(philo, data);
	if (data->nbr_of_times_a_philo_must_eat >= 0)
		philo->nbr_of_times_a_philo_has_eaten++;
	return (0);
}