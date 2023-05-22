#include "../includes/philo_lib.h"


static void	*waitingThread(void *struc)
{
	t_data	*data;

	data = (t_data *)struc;
	sem_wait(data->dead_sem);
	sem_wait(data->stop_sem);
	data->stop = 1;
	sem_post(data->stop_sem);
	return (NULL);
}

static void *ForkThread(void *struc)
{
	int		i;
	t_data	*data;

	data = (t_data *)struc;
	while (1)
	{
		if (dying(data) || data->stop)
		{
			i = 0;
			while (i < data->total_philos)
			{
				sem_post(data->forks_sem);
				i++;
			}
			return (NULL);
		}
	}
	return (NULL);
}

static void	*philo_routine(t_data *data)
{
	if (data->philo_nbr % 2 > 0)
	{
		print_lock(data, "is sleeping");
		if (ft_usleep(data, data->time_to_sleep))
			return (NULL);
		print_lock(data, "is thinking");
		if (data->time_to_eat > data->time_to_sleep && ft_usleep(data, data->time_to_eat - data->time_to_sleep))
			return (NULL);
	}
	while (!dying(data))
	{
		if ((data->nbr_of_times_a_philo_must_eat >= 0 && \
		data->nbr_of_times_a_philo_has_eaten == \
		data->nbr_of_times_a_philo_must_eat))
			sem_post(data->eaten_sem);
		if (eating(data))
			break;
		print_lock(data, "is sleeping");
		if (ft_usleep(data, data->time_to_sleep))
			break;
		print_lock(data, "is thinking");
		if (data->time_to_eat > data->time_to_sleep && ft_usleep(data, data->time_to_eat - data->time_to_sleep))
			return (NULL);
	}
	return (NULL);
}

static void	*routine(void *struc)
{
	t_data	*data;

	data = (t_data *)struc;
	sem_wait(data->sync_sem);
	data->time = current_time();
	data->last_eaten = data->time;
	return (philo_routine(data));
}


int creating_threads(pthread_t thread, t_data *data)
{
	pthread_t	waiting_thread;
	pthread_t	fork_thread;

	if (pthread_create(&thread, NULL, routine, data))
		return (-2);
	if (pthread_create(&waiting_thread, NULL, waitingThread, data))
		return (-4);
	if (pthread_create(&fork_thread, NULL, ForkThread, data))
		return (-4);
	if (pthread_join(thread, NULL))
		return (-1);
	if (pthread_join(waiting_thread, NULL))
		return (-3);
	if (pthread_join(fork_thread, NULL))
		return (-1);
	return (0);
}
