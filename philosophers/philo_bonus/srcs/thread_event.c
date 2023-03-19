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

int	dying(t_philo *philo, t_data *data)
{
	if (data->number_of_philosophers == 1)
		usleep(data->time_to_die * 1000);
	if (current_time() - philo->last_eaten >= data->time_to_die \
		|| data->stop->__align <= 0)
	{
		if (data->stop->__align > 0)
		{
			print_lock(philo, data, "died");
			data->stop->__align = -1;
			exit(1);
		}
		return (1);
	}
	return (0);
}

static void	lock_fork(t_philo *philo, t_data *data)
{
	sem_wait(data->forks);
	print_lock(philo, data, "has taken a fork");
	sem_wait(data->forks);
	print_lock(philo, data, "has taken a fork");
}

static void	unlock_fork(t_data *data)
{
	sem_post(data->forks);
	sem_post(data->forks);
}

void	eating(t_philo *philo, t_data *data)
{
	lock_fork(philo, data);
	print_lock(philo, data, "is eating");
	philo->last_eaten = current_time();
	ft_usleep(philo, data, data->time_to_eat);
	if (data->nbr_of_times_a_philo_must_eat >= 0)
		philo->nbr_of_times_a_philo_has_eaten++;
	unlock_fork(data);
}
