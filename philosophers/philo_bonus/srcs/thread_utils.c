/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:34:43 by nmouslim          #+#    #+#             */
/*   Updated: 2023/03/19 16:34:44 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

long int	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time. tv_usec / 1000);
}

int	ft_usleep(t_philo *philo, t_data *data, long int time_to_do_smth)
{
	long int	time;

	time = current_time();
	while (current_time() < time + time_to_do_smth)
	{
		if (dying(philo, data))
			return (1);
	}
	return (0);
}

void	print_lock(t_philo *philo, t_data *data, char *current_activity)
{
	sem_wait(data->print);
	if (data->stop->__align > 0)
		printf("%ld %d %s\n", current_time() - data->time, \
			philo->philo_nbr, current_activity);
	sem_post(data->print);
}
