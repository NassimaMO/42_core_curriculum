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

/*
   Possible reasons of why it could take more time when thinking:
	- the usleep just after thinking could lead to a longer sleeping time in some cases;
	- it cannot take a fork immediately after thinking because there is too many philosophers on it at the same time;
*/

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
