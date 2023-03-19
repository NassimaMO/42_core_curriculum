/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:34:13 by nmouslim          #+#    #+#             */
/*   Updated: 2023/03/19 16:34:14 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	stock_data(t_data *data, int argc, char **argv)
{
	data->number_of_philosophers = atoi(argv[1]);
	sem_unlink("/sem_print");
	sem_unlink("/sem_forks");
	sem_unlink("/sem_stop");
	data->print = sem_open("/sem_print", O_CREAT, 0644, 1);
	data->forks = sem_open("/sem_forks", O_CREAT, 0644, \
	data->number_of_philosophers);
	data->stop = sem_open("/sem_stop", O_CREAT, 0644, \
	data->number_of_philosophers);
	sem_unlink("/sem_print");
	sem_unlink("/sem_forks");
	sem_unlink("/sem_stop");
	data->pid = malloc(sizeof(int) * data->number_of_philosophers);
	memset(data->pid, 0, sizeof(int));
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
	philo->philo_nbr = data->test;
	philo->last_eaten = data->time;
	philo->nbr_of_times_a_philo_has_eaten = 0;
}
