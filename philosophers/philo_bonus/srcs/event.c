/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:59:08 by nmouslim          #+#    #+#             */
/*   Updated: 2023/05/27 15:59:09 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_lib.h"

static void	one_died(t_data *data)
{
	int	i;

	printf("%ld %d %s\n", current_time() - data->time, data->philo_nbr, "died");
	if (data->nbr_of_times_a_philo_must_eat >= 0)
	{
		i = 0;
		while (i < data->total_philos)
		{
			sem_post(data->eaten_sem);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < data->total_philos)
		{
			sem_post(data->dead_sem);
			i++;
		}
	}
	sem_post(data->stop_sem);
	usleep(300 * 1000);
	sem_post(data->print_sem);
	sem_post(data->last_eat_sem);
}

int	dying(t_data *data)
{
	if (data->total_philos == 1)
	{
		print_lock(data, "has taken a fork");
		usleep(data->time_to_die * 1000);
	}
	sem_wait(data->last_eat_sem);
	if (current_time() - data->last_eaten >= data->time_to_die)
	{
		sem_wait(data->print_sem);
		sem_wait(data->stop_sem);
		if (!data->stop)
			return (one_died(data), 1);
		sem_post(data->stop_sem);
		sem_post(data->print_sem);
	}
	sem_post(data->last_eat_sem);
	sem_wait(data->stop_sem);
	if (data->stop)
		return (sem_post(data->stop_sem), 1);
	return (sem_post(data->stop_sem), 0);
}

static void	lock_fork(t_data *data)
{
	usleep(100);
	sem_wait(data->forks_sem);
	sem_wait(data->forks_sem);
	print_lock(data, "has taken a fork");
	print_lock(data, "has taken a fork");
}

static void	unlock_fork(t_data *data)
{
	sem_post(data->forks_sem);
	sem_post(data->forks_sem);
}

int	eating(t_data *data)
{
	lock_fork(data);
	print_lock(data, "is eating");
	sem_wait(data->last_eat_sem);
	data->last_eaten = current_time();
	sem_post(data->last_eat_sem);
	if (ft_usleep(data, data->time_to_eat) && (unlock_fork(data), 1))
		return (1);
	if (data->nbr_of_times_a_philo_must_eat >= 0)
		data->nbr_of_times_a_philo_has_eaten++;
	unlock_fork(data);
	return (0);
}
