/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:34:05 by nmouslim          #+#    #+#             */
/*   Updated: 2023/03/19 16:34:06 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

/*
	- memory leaks;
	- time not printed correctly;
	- 200 800 200 200;
	- fork managment: need to see if someone already took a fork before someone else take it or smth like that;
*/

/*static void	process_sig(t_data *data, int *pid)
{
	int	i;
	int	status;

	i = 0;
	waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) == 1)
	{
		while (i < data->nbr_philos)
			kill(pid[i++], SIGTERM);
	}
	else if (WEXITSTATUS(status) < 0)
	{
		while (i < data->nbr_philos)
			kill(pid[i++], SIGTERM);
		printf("Thread Error.\n");
	}
	else
	{
		while (i < data->nbr_philos)
			waitpid(pid[i++], NULL, 0);
	}
}
*/

static void	creating_threads(pthread_t thread, t_data *data, int i)
{
	int	pid;
	pthread_t	waitingThread;

	
	pid = fork();
	if (pid == 0)
	{
		data->philo_nbr = i;
		data->time = current_time();
		data->last_eaten = data->time;
		if (pthread_create(&thread, NULL, routine, data))
			exit (-2);
		if (pthread_create(&waitingThread, NULL, routine, data))
			exit (-4);
		if (pthread_join(thread, NULL))
			exit (-1);
		if (pthread_join(waitingThread, NULL))
			exit (-3);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	int			num_threads = atoi(argv[1]);
	pthread_t	threads[num_threads + 1];
	t_data		data;
	int			i;

	i = 0;
	if (arg_verif(argc, argv))
		return (1);
	if (stock_data(&data, argc, argv))
		return (2);
	data.time = current_time();
	while (i < num_threads)
	{
		creating_threads(threads[i], &data, i + 1);
		i++;
	}
	return (0);
}
