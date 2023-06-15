/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:59:15 by nmouslim          #+#    #+#             */
/*   Updated: 2023/05/27 15:59:17 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_lib.h"

void	free_per_process(pthread_t *threads, t_data data, int *pid)
{
	sem_close(data.forks_sem);
	sem_close(data.print_sem);
	sem_close(data.dead_sem);
	sem_close(data.stop_sem);
	sem_close(data.last_eat_sem);
	sem_close(data.eaten_sem);
	sem_unlink("/forks_sem");
	sem_unlink("/print_sem");
	sem_unlink("/dead_sem");
	sem_unlink("/stop_sem");
	sem_unlink("/last_eat_sem");
	sem_unlink("/eaten_sem");
	free(threads);
	free(pid);
}

void	creating_processes(pthread_t *threads, t_data data, int *pid)
{
	int	i;

	i = 0;
	data.time = current_time();
	data.last_eaten = data.time;
	while (i < data.total_philos)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			data.philo_nbr = i + 1;
			if (creating_threads(threads[i], &data) < 0)
			{
				printf("An error occured while trying to create a thread...\n");
			}
			usleep(100);
			free_per_process(threads, data, pid);
			exit(0);
		}
		i++;
	}
}

void	waiting_to_eat(t_data data)
{
	int	i;

	if (data.nbr_of_times_a_philo_must_eat >= 0)
	{
		i = 0;
		while (i < data.total_philos)
		{
			sem_wait(data.eaten_sem);
			i++;
		}
		i = 0;
		while (i < data.total_philos)
		{
			sem_post(data.dead_sem);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int			i;
	int			*pid;
	t_data		data;
	pthread_t	*threads;

	if (verif(argc, argv))
		return (1);
	init_data(&data, argc, argv);
	threads = malloc(data.total_philos * sizeof(pthread_t));
	pid = malloc((data.total_philos + 1) * sizeof(pthread_t));
	creating_processes(threads, data, pid);
	waiting_to_eat(data);
	i = 0;
	while (i < data.total_philos)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
	free_per_process(threads, data, pid);
	return (0);
}
