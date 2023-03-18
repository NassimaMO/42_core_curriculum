#include "new_philo.h"

void	free_data(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->infos);
	pthread_mutex_destroy(&data->print);
	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->forks[i]);
	free(data->forks);
}