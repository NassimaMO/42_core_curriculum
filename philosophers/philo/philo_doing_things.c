#include "philosophers.h"

long int	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec);
}

void	print_lock(t_philosophers **philosopher, char *current_activity, long int time)
{
	pthread_mutex_lock(&(*philosopher)->data->print);
	if (!(*philosopher)->data->philo_stop)
		printf("%ld %d %s\n", time - (*philosopher)->data->time, (*philosopher)->philo_nbr, current_activity);
	pthread_mutex_unlock(&(*philosopher)->data->print);
}

int	dying(t_philosophers **philosopher)
{
	long int	curr_time;

	if ((*philosopher)->data->philo_stop)
		return (1);
	curr_time = current_time();
	if (curr_time - (*philosopher)->last_eaten >= (*philosopher)->data->time_to_die)
		return (print_lock(philosopher, "died", curr_time), (*philosopher)->data->philo_stop++, 1);
	return (0);
}

void	eating(t_philosophers **philosopher)
{
	pthread_mutex_lock(&(*philosopher)->data->forks[(*philosopher)->philo_nbr - 1]);
	print_lock(philosopher, "has taken a fork", current_time());
	if ((*philosopher)->philo_nbr == (*philosopher)->data->number_of_philosophers)
		pthread_mutex_lock(&(*philosopher)->data->forks[0]);
	else
		pthread_mutex_lock(&(*philosopher)->data->forks[(*philosopher)->philo_nbr]);
	print_lock(philosopher, "has taken a fork", current_time());
	print_lock(philosopher, "is eating", current_time());
	(*philosopher)->last_eaten = current_time();
	usleep((*philosopher)->data->time_to_eat);
	(*philosopher)->nbr_of_times_a_philo_has_eaten++;
	pthread_mutex_unlock(&(*philosopher)->data->forks[(*philosopher)->philo_nbr - 1]);
	if ((*philosopher)->philo_nbr == (*philosopher)->data->number_of_philosophers)
		pthread_mutex_unlock(&(*philosopher)->data->forks[0]);
	else
		pthread_mutex_unlock(&(*philosopher)->data->forks[(*philosopher)->philo_nbr]);
}