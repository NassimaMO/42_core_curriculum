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
		if (ft_usleep(philo, data, data->time_to_sleep))
			return (NULL);
		print_lock(philo, data, THINK);
		if (data->time_to_sleep < data->time_to_eat)
		{
			if (ft_usleep(philo, data, data->time_to_eat - data->time_to_sleep))
				return (NULL);
		}
	}
	while (1)
	{
		if (eating(philo, data))
			break ;
		print_lock(philo, data, SLEEP);
		if (ft_usleep(philo, data, data->time_to_sleep))
			break ;
		print_lock(philo, data, THINK);
		if (data->nbr_philos % 2 > 0)
			usleep(2000);
		if (data->time_to_eat > data->time_to_sleep)
			ft_usleep(philo, data, (data->time_to_eat - data->time_to_sleep) + 1);
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
	while (data->time == 0)
	{
		if (philo.philo_nbr == data->nbr_philos)
			data->time = current_time();
	}
	philo.last_eaten = data->time;
	return (philo_routine(&philo, data));
}
