/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:27 by nmouslim          #+#    #+#             */
/*   Updated: 2022/11/26 14:12:29 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_data(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->print);
	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->forks[i]);
	free(data->forks);
	free(data);
}

void	free_list(t_philosophers **philosophers)
{
	t_philosophers	*tmp;
	int				i;
	int				num;

	num = (*philosophers)->data->number_of_philosophers;
	free_data((*philosophers)->data);
	tmp = *philosophers;
	i = -1;
	while (++i < num)
	{
		tmp = *philosophers;
		*philosophers = (*philosophers)->next;
		free(tmp);
	}
}

void	free_thread(t_philosophers *philosopher)
{
	(void) philosopher;
}
