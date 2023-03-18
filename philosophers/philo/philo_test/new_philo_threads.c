#include "new_philo.h"

void	*philo_routine(t_philo *philo, t_data *data)
{
	if (philo->philo_nbr % 2 > 0)
	{
		print_lock(philo, data, "is sleeping");
		ft_usleep(philo, data, data->time_to_sleep);
		print_lock(philo, data, "is thinking");
/* 		ft_usleep(philo, data, 10);
 */	}
	while (!dying(philo, data))
	{
		eating(philo, data);
		print_lock(philo, data, "is sleeping");
		ft_usleep(philo, data, data->time_to_sleep);
		print_lock(philo, data, "is thinking");
/* 		ft_usleep(philo, data, 10);
 */		if ((data->nbr_of_times_a_philo_must_eat >= 0 && \
		philo->nbr_of_times_a_philo_has_eaten == \
		data->nbr_of_times_a_philo_must_eat))
		{
			pthread_mutex_lock(&data->infos);
			data->philo_stop++;
			pthread_mutex_unlock(&data->infos);
		}
	}
	return (NULL);
}

void    *routine(void *struc)
{
	t_data	*data;
	t_philo philo;

	data = (t_data *)struc;
	philo_init(&philo, data);
	return (philo_routine(&philo, data));
}