/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:26:16 by nmouslim          #+#    #+#             */
/*   Updated: 2023/03/19 16:26:18 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	stock_data(t_data *data, int argc, char **argv)
{
	int	i;

	pthread_mutex_init(&data->sync, NULL);
	pthread_mutex_init(&data->infos, NULL);
	pthread_mutex_init(&data->print, NULL);
	data->nbr_philos = atoi(argv[1]);
	data->forks = malloc(data->nbr_philos * \
		sizeof(pthread_mutex_t));
	data->tab_forks = malloc(data->nbr_philos * sizeof(int));
	i = -1;
	while (++i < data->nbr_philos)
		pthread_mutex_init(&data->forks[i], NULL), data->tab_forks[i] = 0;
	data->philo_stop = 0;
	data->time = 0;
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	data->nbr_of_times_a_philo_must_eat = -1;
	if (argc == 6)
		data->nbr_of_times_a_philo_must_eat = atoi(argv[5]);
	data->test = 1;
	return (0);
}

void	philo_init(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->infos);
	philo->philo_nbr = data->test;
	data->test++;
	pthread_mutex_unlock(&data->infos);
	philo->last_eaten = data->time;
	philo->nbr_of_times_a_philo_has_eaten = 0;
	philo->philo_odd = 0;
}
