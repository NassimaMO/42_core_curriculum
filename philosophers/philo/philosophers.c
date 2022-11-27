/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:02 by nmouslim          #+#    #+#             */
/*   Updated: 2022/11/27 14:39:32 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine_loop(t_philosophers *philo)
{
	while (!dying(philo))
	{
		eating(philo);
		print_lock(philo, "is sleeping");
		if (philo->data->time_to_eat < philo->data->time_to_die && \
			(current_time() - philo->last_eaten) + philo->data->time_to_sleep <= \
			philo->data->time_to_die && !philo->data->philo_stop)
			usleep(philo->data->time_to_sleep * 1000);
		else if (philo->data->time_to_eat < philo->data->time_to_die && \
				philo->data->time_to_eat + philo->data->time_to_sleep > \
				philo->data->time_to_die && !philo->data->philo_stop)
			usleep((philo->data->time_to_die - (current_time() - \
			philo->data->time)) * 1000);
		if (!dying(philo))
			print_lock(philo, "is thinking");
		if ((philo->data->nbr_of_times_a_philo_must_eat >= 0 && \
		philo->nbr_of_times_a_philo_has_eaten >= \
		philo->data->nbr_of_times_a_philo_must_eat))
			return (NULL);
	}
	return (NULL);
}

void	*routine(void *philosopher)
{
	t_philosophers	*philo;

	philo = (t_philosophers *)philosopher;
	philo->last_eaten = philo->data->time;
	print_lock(philo, "is thinking");
	if ((philo->data->time_to_eat > philo->data->time_to_die && \
		philo->philo_nbr % 2 == philo->data->number_of_philosophers % 2) || \
		philo->data->number_of_philosophers == 1)
		usleep(philo->data->time_to_die * 1000);
	else if (philo->philo_nbr % 2 == philo->data->number_of_philosophers % 2)
		usleep(philo->data->time_to_eat * 1000);
	return (routine_loop(philo));
}

int	creat_thread(t_philosophers *philos)
{
	t_philosophers	*philo;
	int				i;

	philo = philos;
	i = -1;
	philo->data->time = current_time();
	while (++i < philos->data->number_of_philosophers)
	{
		if (pthread_create(&philo->thread, NULL, routine, philo))
			return (1);
		philo = philo->next;
	}
	philo = philos;
	i = -1;
	while (++i < philos->data->number_of_philosophers)
	{
		if (pthread_join(philo->thread, NULL))
			return (2);
		philo = philo->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philosophers	*philos;
	t_data			*data;

	if (arg_verif(argc, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (stock_data(data, argc, argv))
		return (1);
	creat_list(&philos, data);
	creat_thread(philos);
	free_list(philos);
}
