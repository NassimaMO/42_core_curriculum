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
	data->nbr_philos = atoi(argv[1]);
	sem_unlink("/sem_print");
	sem_unlink("/sem_forks");
	sem_unlink("/sem_die");
	sem_unlink("/sem_stop");
	data->print = sem_open("/sem_print", O_CREAT, 0644, 1);
	data->forks = sem_open("/sem_forks", O_CREAT, 0644, \
	data->nbr_philos);
	data->die = sem_open("/sem_die", O_CREAT, 0644, 0);
	data->sem_stop = sem_open("/sem_stop", O_CREAT, 0644, 1);
	data->stop = 0;
	data->nbr_of_times_a_philo_has_eaten = 0;
	data->time = 0;
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	data->nbr_of_times_a_philo_must_eat = -1;
	if (argc == 6)
		data->nbr_of_times_a_philo_must_eat = atoi(argv[5]);
	return (0);
}