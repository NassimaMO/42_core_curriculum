/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:34:20 by nmouslim          #+#    #+#             */
/*   Updated: 2023/03/19 16:34:21 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	dying(t_data *data)
{
	int	i;

	i = 0;
	if (data->nbr_philos == 1)
		usleep(data->time_to_die * 1000);
	sem_wait(data->sem_stop);
	if (current_time() - data->last_eaten >= data->time_to_die)
	{
		print_lock(data, "died");
		while (i < data->nbr_philos)
		{
			sem_post(data->die);
			i++;
		}
	}
	if (data->stop) //data race ?
	{
		sem_post(data->sem_stop);
		sem_post(data->die);
		sem_close(data->forks);
		sem_close(data->print);
		sem_close(data->die);
		sem_close(data->sem_stop);
		exit(1);
	}
	sem_post(data->sem_stop);
	return (0);
}

static void	lock_fork(t_data *data)
{
	sem_wait(data->forks);
	sem_wait(data->forks);
	print_lock(data, "has taken a fork");
	print_lock(data, "has taken a fork");
}

static void	unlock_fork(t_data *data)
{
	sem_post(data->forks);
	sem_post(data->forks);
}

void	eating(t_data *data)
{
	lock_fork(data);
	print_lock(data, "is eating");
	sem_wait(data->sem_stop);
	data->last_eaten = current_time();
	sem_post(data->sem_stop);
	ft_usleep(data, data->time_to_eat);
	if (data->nbr_of_times_a_philo_must_eat >= 0)
		data->nbr_of_times_a_philo_has_eaten++;
	unlock_fork(data);
}
