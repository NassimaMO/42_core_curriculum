/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:27 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/05 11:37:53 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_data(t_data *data)
{
	int	i;

	sem_destroy(&data->print);
	i = -1;
	while (++i < data->number_of_philosophers)
		sem_destroy(&data->forks[i]);
	free(data->forks);
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
