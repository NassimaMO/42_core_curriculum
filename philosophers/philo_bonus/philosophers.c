/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:02 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/26 19:12:16 by nmouslim         ###   ########.fr       */
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
		philo->nbr_of_times_a_philo_has_eaten == \
		philo->data->nbr_of_times_a_philo_must_eat))
			{printf("align=%ld, %d\n", philo->data->stop->__align, sem_wait(philo->data->stop)); return (NULL);}
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

int	get_pid_cp(int pid, int p)
{
	static int id;

	//printf("p=%d, pid=%d\n", p, pid);
	if (p == 1)
		return (id);
	id = pid;
	printf("||||||||||||pid=%d\n", pid);
	return (0);
}

int	creat_thread(t_philosophers *philo, int i)
{
	int	pid;
	
	philo->data->time = current_time();
	pid = fork();
	if (pid > 0)
	{
		get_pid_cp(pid, 0);
		printf("1\n");
	}
	if (pid == 0)
	{
		usleep(10);
		philo->data->pid[i] = get_pid_cp(philo, pid, 1);
		printf("2\n");
		printf("|||||||||||child_pid=%d\n", philo->data->pid[i]);
		return (0);
		if (pthread_create(&philo->thread, NULL, routine, philo))
			return (-2);
		if (pthread_join(philo->thread, NULL))
			return (-1);
	}
	return (pid);
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
		usleep(10);
		if (creat_thread(philo, i) == 0)
			break;
		philo = philo->next;
	}
  	waitpid(-1, NULL, 0);
	free_list(philos);
}
