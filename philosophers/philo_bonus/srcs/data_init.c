/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:58:57 by nmouslim          #+#    #+#             */
/*   Updated: 2023/05/27 15:59:01 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_lib.h"

void	init_data(t_data *data, int argc, char **argv)
{
	data->total_philos = ft_atoi(argv[1]);
	sem_unlink("/print_sem");
	sem_unlink("/forks_sem");
	sem_unlink("/dead_sem");
	sem_unlink("/stop_sem");
	sem_unlink("/last_eat_sem");
	sem_unlink("/eaten_sem");
	data->last_eat_sem = sem_open("/last_eat_sem", O_CREAT, 0644, 1);
	data->print_sem = sem_open("/print_sem", O_CREAT, 0644, 1);
	data->forks_sem = sem_open("/forks_sem", O_CREAT, 0644, \
	data->total_philos);
	data->eaten_sem = sem_open("/eaten_sem", O_CREAT, 0644, 0);
	data->dead_sem = sem_open("/dead_sem", O_CREAT, 0644, 0);
	data->stop_sem = sem_open("/stop_sem", O_CREAT, 0644, 1);
	data->stop = 0;
	data->nbr_of_times_a_philo_has_eaten = 0;
	data->time = 0;
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->nbr_of_times_a_philo_must_eat = -1;
	if (argc == 6)
		data->nbr_of_times_a_philo_must_eat = ft_atoi(argv[5]);
}
