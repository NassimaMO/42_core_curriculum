/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:27 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/26 13:09:58 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
