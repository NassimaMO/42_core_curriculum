/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:27 by nmouslim          #+#    #+#             */
/*   Updated: 2023/01/31 12:31:55 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	end(t_philosophers *philos)
{
	int	i;
	int	status;

	i = 0;
  	waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) == 1)
	{
		while (i < philos->data->number_of_philosophers)
			kill(philos->data->pid[i++], SIGTERM);
	}
	else if (WEXITSTATUS(status) < 0)
	{
		while (i < philos->data->number_of_philosophers)
			kill(philos->data->pid[i++], SIGTERM);
		printf("Thread Error.\n");
	}
	else
	{
		while (i < philos->data->number_of_philosophers)
			waitpid(philos->data->pid[i++], NULL, 0);
	}
}

void	free_data(t_data *data)
{
	sem_close(data->print);
	sem_close(data->forks);
	sem_close(data->stop);
	free(data->pid);
	free(data);
}

void	free_list(t_philosophers *philos)
{
	t_philosophers	*tmp;
	int				i;
	int				num;

	num = philos->data->number_of_philosophers;
	free_data(philos->data);
	tmp = philos;
	i = -1;
	while (++i < num)
	{
		tmp = philos;
		philos = philos->next;
		free(tmp);
	}
}

void	free_thread(t_philosophers *philos)
{
	(void) philos;
}
