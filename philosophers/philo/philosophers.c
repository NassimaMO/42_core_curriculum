/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:12:02 by nmouslim          #+#    #+#             */
/*   Updated: 2022/11/26 16:12:08 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *philosopher)
{
	t_philosophers	*tmp;

	tmp = (t_philosophers *)philosopher;
	tmp->last_eaten = tmp->data->time;
	print_lock(&tmp, "is thinking");
	if ((tmp->data->time_to_eat > tmp->data->time_to_die && \
		tmp->philo_nbr % 2 == tmp->data->number_of_philosophers % 2) || \
		tmp->data->number_of_philosophers == 1)
		usleep(tmp->data->time_to_die * 1000);
	else if (tmp->philo_nbr % 2 == tmp->data->number_of_philosophers % 2)
		usleep(tmp->data->time_to_eat * 1000);
	while (!dying(&tmp))
	{
		eating(&tmp);
		print_lock(&tmp, "is sleeping");
		if (tmp->data->time_to_eat < tmp->data->time_to_die && (current_time() - tmp->last_eaten) + tmp->data->time_to_sleep < tmp->data->time_to_die)
			usleep(tmp->data->time_to_sleep * 1000);
		else if (tmp->data->time_to_eat < tmp->data->time_to_die && tmp->data->time_to_eat + tmp->data->time_to_sleep > tmp->data->time_to_die)
			usleep((tmp->data->time_to_die - tmp->data->time_to_sleep) * 1000);
		if (!dying(&tmp))
			print_lock(&tmp, "is thinking");
		if ((tmp->data->nbr_of_times_a_philo_must_eat >= 0 && \
		tmp->nbr_of_times_a_philo_has_eaten >= \
		tmp->data->nbr_of_times_a_philo_must_eat))
			return (NULL);
	}
	return (NULL);
}

int	creat_thread(t_philosophers *philosophers)
{
	t_philosophers	*tmp;
	int				i;

	tmp = philosophers;
	i = -1;
	tmp->data->time = current_time();
	while (++i < philosophers->data->number_of_philosophers)
	{
		if (pthread_create(&tmp->thread, NULL, routine, tmp))
			return (1);
		tmp = tmp->next;
	}
	tmp = philosophers;
	i = -1;
	while (++i < philosophers->data->number_of_philosophers)
	{
		if (pthread_join(tmp->thread, NULL))
			return (2);
		tmp = tmp->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philosophers	*philosophers;
	t_data			*data;

	if (arg_verif(argc, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (stock_data(data, argc, argv))
		return (1);
	creat_list(&philosophers, data);
	creat_thread(philosophers);
	free_list(&philosophers);
}
