/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:02 by nmouslim          #+#    #+#             */
/*   Updated: 2023/01/03 11:49:52 by nmouslim         ###   ########.fr       */
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
			philo->data->stop->__align--;
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

int	get_pid_cp(int	pid, int p)
{
	static int id;

	if (p == 1)
		return (id);
	id = pid;
	return (0);
}

int	creat_thread(t_philosophers *philo, int i)
{
	int	pid;
	
	philo->data->time = current_time();
	pid = fork();
	if (pid > 0)
		get_pid_cp(pid, 0);
	if (pid == 0)
	{
		philo->data->pid[i] = get_pid_cp(pid, 1);
		//printf("|||||||||||child_pid=%d\n", philo->data->pid[i]);
		//return (0);
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
		if (creat_thread(philo, i) == 0) //take the return value and do smt with it in the loop or smt IDK its so weirdddd fuck this shit haaaaaaaaaaaaaaaaaaaa
			break;
		philo = philo->next;
	}
  	waitpid(-1, NULL, 0);
	free_list(philos);
}
