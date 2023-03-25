/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:26:43 by nmouslim          #+#    #+#             */
/*   Updated: 2023/03/19 16:26:44 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_data(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->infos);
	pthread_mutex_destroy(&data->print);
	i = 0;
	while (i < data->nbr_philos)
		pthread_mutex_destroy(&data->forks[i++]);
	free(data->tab_forks);
	free(data->forks);
}
