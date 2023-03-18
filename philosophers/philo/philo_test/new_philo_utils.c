#include "new_philo.h"

long int	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time. tv_usec / 1000);
}

void	ft_usleep(t_philo *philo, t_data *data, long int time_to_do_smth)
{
	long int	time;

	time = current_time();
	while (current_time() < time + time_to_do_smth)
	{
		pthread_mutex_lock(&data->infos);
		if (data->philo_stop >= data->number_of_philosophers)
			return ((void)pthread_mutex_unlock(&data->infos));
		pthread_mutex_unlock(&data->infos);
		if (dying(philo, data))
			return ;
	}
}

void	print_lock(t_philo *philo, t_data *data, char *current_activity)
{
	pthread_mutex_lock(&data->print);
	pthread_mutex_lock(&data->infos);
	if (data->philo_stop < data->number_of_philosophers)
		printf("%ld %d %s\n", current_time() - data->time, \
				philo->philo_nbr, current_activity);
	pthread_mutex_unlock(&data->infos);
	pthread_mutex_unlock(&data->print);
}