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
		if ((data->nbr_of_times_a_philo_must_eat >= 0 && \
		philo->nbr_of_times_a_philo_has_eaten == \
		data->nbr_of_times_a_philo_must_eat))
			data->stop->__align--;
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
