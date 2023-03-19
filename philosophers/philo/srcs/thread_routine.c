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
		print_lock(philo, data, "is sleeping");
		ft_usleep(philo, data, data->time_to_sleep);
		print_lock(philo, data, "is thinking");
	}
	while (!dying(philo, data))
	{
		eating(philo, data);
		print_lock(philo, data, "is sleeping");
		ft_usleep(philo, data, data->time_to_sleep);
		print_lock(philo, data, "is thinking");
		if (data->time_to_sleep < data->time_to_eat && \
			data->time_to_die > current_time() - philo->last_eaten)
			ft_usleep(philo, data, data->time_to_die - \
			(current_time() - philo->last_eaten));
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
