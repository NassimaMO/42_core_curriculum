#include "../includes/philo_lib.h"

long int	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time. tv_usec / 1000);
}

int	ft_usleep(t_data *data, long int time_to_do_smth)
{
	long int	time;

	time = current_time();
	while (current_time() < time + time_to_do_smth)
	{
		if (dying(data))
			return (1);
	}
	return (0);
}

void	print_lock(t_data *data, char *current_activity)
{
	sem_wait(data->print_sem);
	usleep(1 * 1000);
	sem_wait(data->stop_sem);
	if (!data->stop)
		printf("%ld %d %s\n", current_time() - data->time, \
			data->philo_nbr, current_activity);
	sem_post(data->stop_sem);
	sem_post(data->print_sem);
}