/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:02 by nmouslim          #+#    #+#             */
/*   Updated: 2023/01/29 15:08:53 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine_loop(t_philosophers *philo)
{
	while (!dying(philo))
	{
		eating(philo);
		print_lock(philo, "is sleeping");
		ft_usleep(philo, philo->data->time_to_sleep);
		if (!dying(philo))
			print_lock(philo, "is thinking");
		if ((philo->data->nbr_of_times_a_philo_must_eat >= 0 && \
		philo->nbr_of_times_a_philo_has_eaten == \
		philo->data->nbr_of_times_a_philo_must_eat))
			philo->data->philo_stop++;
	}
	return (NULL);
}

void	*routine(void *philosopher)
{
	t_philosophers	*philo;

	philo = (t_philosophers *)philosopher;
	philo->last_eaten = philo->data->time;
	print_lock(philo, "is thinking");
	if (philo->philo_nbr % 2 == philo->data->number_of_philosophers % 2)
		ft_usleep(philo, philo->data->time_to_eat);
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
		/*pthread_mutex_lock(&philo->data->print);
		printf("heeyyy %d\n", i + 1);
		pthread_mutex_unlock(&philo->data->print);*/
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
