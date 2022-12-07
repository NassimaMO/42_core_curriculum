/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:34 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/05 11:51:45 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	creat_list(t_philosophers **philos, t_data *data)
{
	int				i;
	t_philosophers	*tmp;
	t_philosophers	*last_tmp;

	tmp = malloc(sizeof(t_philosophers));
	tmp->philo_nbr = 1;
	tmp->last_eaten = 0;
	tmp->nbr_of_times_a_philo_has_eaten = 0;
	tmp->data = data;
	*philos = tmp;
	last_tmp = tmp;
	tmp = tmp->next;
	i = 0;
	while (++i < data->number_of_philosophers)
	{
		tmp = malloc(sizeof(t_philosophers));
		tmp->philo_nbr = i + 1;
		tmp->last_eaten = 0;
		tmp->nbr_of_times_a_philo_has_eaten = 0;
		tmp->data = data;
		last_tmp->next = tmp;
		last_tmp = tmp;
		tmp = tmp->next;
	}
}

t_data	*stock_data(int argc, char **argv)
{
	int		i;
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->number_of_philosophers = atoi(argv[1]);
	sem_init(&data->print, PTHREAD_PROCESS_SHARED, data->number_of_philosophers);
	data->forks = malloc(data->number_of_philosophers * \
		sizeof(sem_t));
	i = -1;
	while (++i < data->number_of_philosophers)
		sem_init(&data->forks[i], PTHREAD_PROCESS_SHARED, data->number_of_philosophers);
	data->philo_stop = 0;
	data->time = 0;
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	data->nbr_of_times_a_philo_must_eat = -1;
	if (argc == 6)
		data->nbr_of_times_a_philo_must_eat = atoi(argv[5]);
	if (data->time_to_sleep < 60 || data->time_to_eat < 60)
		return (free_data(data), NULL);
	return (data);
}
