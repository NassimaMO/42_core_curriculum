/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:26:23 by nmouslim          #+#    #+#             */
/*   Updated: 2023/03/19 16:26:24 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_routine(t_philo *philo, t_data *data)
{
	if (philo->philo_nbr % 2 > 0)
	{
		print_lock(philo, data, SLEEP);
		ft_usleep(philo, data, data->time_to_sleep);
		print_lock(philo, data, THINK);
	}
	while (!dying(philo, data))
	{
		eating(philo, data);
		print_lock(philo, data, SLEEP);
		ft_usleep(philo, data, data->time_to_sleep);
		print_lock(philo, data, THINK);
		if (data->time_to_eat + (data->time_to_eat - data->time_to_sleep) * 2 > data->time_to_die)
			ft_usleep(philo, data, data->time_to_die - \
			(current_time() - philo->last_eaten));
		if (!philo->philo_odd && data->number_of_philosophers % 2 > 0 && philo->philo_nbr == data->number_of_philosophers - 1)
				ft_usleep(philo, data, data->time_to_eat + data->time_to_sleep), philo->philo_odd++;
		if ((data->nbr_of_times_a_philo_must_eat >= 0 && \
		philo->nbr_of_times_a_philo_has_eaten == \
		data->nbr_of_times_a_philo_must_eat))
		{
			pthread_mutex_lock(&data->infos);
			data->philo_stop++;
			pthread_mutex_unlock(&data->infos);
		}
	}
	return (NULL);
}

void	*routine(void *struc)
{
	t_data	*data;
	t_philo	philo;

	data = (t_data *)struc;
	philo_init(&philo, data);
	return (philo_routine(&philo, data));
}
