/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:02 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/24 19:47:35 by nmouslim         ###   ########.fr       */
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
	if (philo->philo_nbr % 2 == philo->data->number_of_philosophers % 2)
		ft_usleep(philo, philo->data->time_to_eat);
	return (routine_loop(philo));
}

int	creat_thread(t_philosophers *philo)
{
	int				pid;

	philo->data->time = current_time();
	pid = fork();
	if (pid == 0)
	{
		if (pthread_create(&philo->thread, NULL, routine, philo))
			return (1);
		if (pthread_join(philo->thread, NULL))
			return (2);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philosophers	*philos;
	t_philosophers	*philo;
	t_data			*data;
	int				i;

	if (arg_verif(argc, argv))
		return (1);
	data = stock_data(argc, argv);
	if (!data)
		return (1);
	creat_list(&philos, data);
	philo = philos;
	i = -1;
	while (++i < philos->data->number_of_philosophers)
	{
		creat_thread(philo);
		philo = philo->next;
	}
  	waitpid(-1, NULL, 0);
	free_list(philos);
}
