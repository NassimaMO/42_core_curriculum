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
	while (1)
	{
		if (eating(philo, data))
			break ;
		print_lock(philo, data, SLEEP);
		if (ft_usleep(philo, data, data->time_to_sleep))
			break ;
		print_lock(philo, data, THINK);
		ft_usleep(philo, data, 5);
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
	pthread_mutex_lock(&data->sync);
	philo_init(&philo, data);
	pthread_mutex_unlock(&data->sync);
	philo.last_eaten = data->time;
	if (philo.philo_nbr % 2 > 0)
	{
		print_lock(&philo, data, SLEEP);
		if (ft_usleep(&philo, data, data->time_to_sleep))
			return (NULL);
		print_lock(&philo, data, THINK);
		if (data->time_to_sleep < data->time_to_eat)
		{
			if (ft_usleep(&philo, data, data->time_to_eat - \
			data->time_to_sleep))
				return (NULL);
		}
	}
	return (philo_routine(&philo, data));
}
