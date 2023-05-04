/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:34:33 by nmouslim          #+#    #+#             */
/*   Updated: 2023/03/19 16:34:34 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*waitingThread(void *struc)
{
	t_data	*data;

	data = (t_data *)struc;
	sem_wait(data->die);
	sem_wait(data->sem_stop);
	data->stop = 1;
	sem_post(data->sem_stop);
	return (NULL);
}

void	*routine(void *struc)
{
	t_data	*data;

	data = (t_data *)struc;
	if (data->philo_nbr % 2 == 0)
	{
		print_lock(data, "is sleeping");
		ft_usleep(data, data->time_to_sleep);
		print_lock(data, "is thinking");
	}
	while (!dying(data))
	{
		eating(data);
		print_lock(data, "is sleeping");
		ft_usleep(data, data->time_to_sleep);
		print_lock(data, "is thinking");
		/*if ((data->nbr_of_times_a_philo_must_eat >= 0 && \
		data->nbr_of_times_a_philo_has_eaten == \
		data->nbr_of_times_a_philo_must_eat))
			data->stop = 2;*/
	}
	return (NULL);
}
