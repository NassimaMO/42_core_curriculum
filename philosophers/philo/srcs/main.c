/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:25:59 by nmouslim          #+#    #+#             */
/*   Updated: 2023/03/19 16:26:05 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	pthread_t	*threads;
	t_data		data;
	int			i;

	i = 0;
	if (arg_verif(argc, argv))
		return (1);
	if (stock_data(&data, argc, argv))
		return (2);
	threads = malloc(data.nbr_philos * sizeof(pthread_t));
	pthread_mutex_lock(&data.sync);
	while (i < data.nbr_philos)
	{
		if (pthread_create(&threads[i++], NULL, routine, &data))
			return (3);
	}
	data.time = (usleep(50), current_time());
	pthread_mutex_unlock(&data.sync);
	i = 0;
	while (i < data.nbr_philos)
	{
		if (pthread_join(threads[i++], NULL))
			return (4);
	}
	return (free(threads), free_data(&data), 0);
}
