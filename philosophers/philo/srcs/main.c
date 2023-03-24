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
	int			num_threads = atoi(argv[1]);
	pthread_t	threads[num_threads + 1];
	t_data		data;
	int			i;

	i = 0;
	if (arg_verif(argc, argv))
		return (1);
	if (stock_data(&data, argc, argv))
		return (2);
	//data.time = current_time();
	while (i < num_threads)
	{
		if (pthread_create(&threads[i++], NULL, routine, &data))
			return (3);
	}
	i = 0;
	while (i < num_threads)
	{
		if (pthread_join(threads[i++], NULL))
			return (4);
	}
	free_data(&data);
	return (0);
}
