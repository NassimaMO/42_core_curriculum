#include "new_philo.h"

int	stock_data(t_data *data, int argc, char **argv)
{
	int	i;

	pthread_mutex_init(&data->stop, NULL);
	pthread_mutex_init(&data->print, NULL);
	data->number_of_philosophers = atoi(argv[1]);
	data->forks = malloc(data->number_of_philosophers * \
		sizeof(pthread_mutex_t));
	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_mutex_init(&data->forks[i], NULL);
	data->philo_stop = 0;
	data->time = 0;
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	data->nbr_of_times_a_philo_must_eat = -1;
	if (argc == 6)
		data->nbr_of_times_a_philo_must_eat = atoi(argv[5]);
	data->test = 0;
	return (0);
}

void	philo_init(t_philo *philo, int num)
{
	philo->philo_nbr = num;
	philo->last_eaten = 0;
	philo->nbr_of_times_a_philo_has_eaten = 0;
}