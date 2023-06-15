/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:59:23 by nmouslim          #+#    #+#             */
/*   Updated: 2023/05/27 15:59:25 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_lib.h"

static void	*waiting_th(void *struc)
{
	t_data	*data;

	data = (t_data *)struc;
	sem_wait(data->dead_sem);
	sem_wait(data->stop_sem);
	data->stop = 1;
	sem_post(data->stop_sem);
	return (NULL);
}

static void	*fork_th(void *struc)
{
	int		i;
	t_data	*data;

	data = (t_data *)struc;
	while (1)
	{
		usleep(10);
		if (dying(data) || (sem_wait(data->stop_sem), data->stop))
		{
			i = 0;
			while (i < data->total_philos)
			{
				sem_post(data->forks_sem);
				i++;
			}
			return (sem_post(data->stop_sem), NULL);
		}
		sem_post(data->stop_sem);
	}
	return (NULL);
}

static void	*philo_routine(t_data *data)
{
	while (!dying(data))
	{
		if ((data->nbr_of_times_a_philo_must_eat >= 0 && \
		data->nbr_of_times_a_philo_has_eaten == \
		data->nbr_of_times_a_philo_must_eat))
			sem_post(data->eaten_sem);
		if (eating(data))
			break ;
		print_lock(data, "is sleeping");
		if (ft_usleep(data, data->time_to_sleep))
			break ;
		print_lock(data, "is thinking");
		if (data->time_to_eat > data->time_to_sleep && \
		ft_usleep(data, data->time_to_eat - data->time_to_sleep))
			return (NULL);
	}
	return (NULL);
}

static void	*routine(void *struc)
{
	t_data	*data;

	data = (t_data *)struc;
	if (data->philo_nbr % 2 > 0)
	{
		print_lock(data, "is sleeping");
		if (ft_usleep(data, data->time_to_sleep))
			return (NULL);
		print_lock(data, "is thinking");
		if (data->time_to_eat > data->time_to_sleep && ft_usleep(data, \
		data->time_to_eat - data->time_to_sleep))
			return (NULL);
	}
	return (philo_routine(data));
}

int	creating_threads(pthread_t thread, t_data *data)
{
	pthread_t	waiting_thread;
	pthread_t	fork_thread;

	/*sem_unlink("/stop_sem");
	data->stop_sem = sem_open("/stop_sem", O_CREAT, 0644, 1);*/
	if (pthread_create(&thread, NULL, routine, data))
		return (-2);
	if (pthread_create(&waiting_thread, NULL, waiting_th, data))
		return (-4);
	if (pthread_create(&fork_thread, NULL, fork_th, data))
		return (-4);
	if (pthread_join(thread, NULL))
		return (-1);
	if (pthread_join(waiting_thread, NULL))
		return (-3);
	if (pthread_join(fork_thread, NULL))
		return (-1);
	return (0);
}
