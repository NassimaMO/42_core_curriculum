/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:02 by nmouslim          #+#    #+#             */
/*   Updated: 2023/02/16 16:25:03 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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
		{
			pthread_mutex_lock(&philo->data->stop);
			philo->data->philo_stop++;
			pthread_mutex_unlock(&philo->data->stop);
		}
	}
	return (NULL);
}

void	*routine(void *philosopher)
{
	t_philosophers	*philo;

	philo = (t_philosophers *)philosopher;
	philo->last_eaten = philo->data->time;
	if (philo->philo_nbr % 2 > 0)
	{
		usleep(10);
		/*print_lock(philo, "is sleeping");
		ft_usleep(philo, philo->data->time_to_sleep);
		print_lock(philo, "is thinking");*/
	}
	return (routine_loop(philo));
}

int	creat_thread(t_philosophers *philos)
{
	t_philosophers		*tmp;
	int					i;

	tmp = philos;
	i = 0;
	philos->data->time = current_time();
	while (i < philos->data->number_of_philosophers)
	{
		if (pthread_create(&tmp->thread, NULL, routine, tmp))
			return (1);
		tmp = tmp->next;
		i++;
	}
	tmp = philos;
	i = 0;
	while (i < philos->data->number_of_philosophers)
	{
		if (pthread_join(tmp->thread, NULL))
			return (2);
		tmp = tmp->next;
		i++;
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
	if (creat_thread(philos))
		return (printf("Thread error."), 1);
	free_list(philos);
}
