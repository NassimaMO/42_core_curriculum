#include "philosophers.h"

int	dying(t_philosophers **philosopher)
{
	gettimeofday(&((*philosopher)->data->curr_time), NULL);
	if ((((*philosopher)->data->curr_time.tv_usec - (*philosopher)->data->time) + ((*philosopher)->last_eaten - (*philosopher)->data->time)) >= (*philosopher)->data->time_to_die)
		return (printf("%ld %d died\n", (*philosopher)->data->curr_time.tv_usec - (*philosopher)->data->time, (*philosopher)->philo_nbr), 1);
	return (0);
}

void	thinking(t_philosophers **philosopher)
{
	gettimeofday(&((*philosopher)->data->curr_time), NULL);
	printf("%ld %d is thinking\n", (*philosopher)->data->curr_time.tv_usec - (*philosopher)->data->time, (*philosopher)->philo_nbr);
}

void	eating(t_philosophers **philosopher)
{
	pthread_mutex_lock(&(*philosopher)->data->forks[(*philosopher)->philo_nbr - 1]);
	gettimeofday(&((*philosopher)->data->curr_time), NULL);
	printf("%ld %d has taken a fork\n", (*philosopher)->data->curr_time.tv_usec - (*philosopher)->data->time, (*philosopher)->philo_nbr);
	if ((*philosopher)->philo_nbr == (*philosopher)->data->number_of_philosophers)
		pthread_mutex_lock(&(*philosopher)->data->forks[0]);
	else
		pthread_mutex_lock(&(*philosopher)->data->forks[(*philosopher)->philo_nbr]);
	gettimeofday(&((*philosopher)->data->curr_time), NULL);
	printf("%ld %d has taken a fork\n", (*philosopher)->data->curr_time.tv_usec - (*philosopher)->data->time, (*philosopher)->philo_nbr);
	gettimeofday(&((*philosopher)->data->curr_time), NULL);
	printf("%ld %d is eating\n", (*philosopher)->data->curr_time.tv_usec - (*philosopher)->data->time, (*philosopher)->philo_nbr);
	(*philosopher)->last_eaten = (*philosopher)->data->curr_time.tv_usec;
	usleep((*philosopher)->data->time_to_eat);
	(*philosopher)->nbr_of_times_a_philo_has_eaten++;
	pthread_mutex_unlock(&(*philosopher)->data->forks[(*philosopher)->philo_nbr - 1]);
	if ((*philosopher)->philo_nbr == (*philosopher)->data->number_of_philosophers)
		pthread_mutex_unlock(&(*philosopher)->data->forks[0]);
	else
		pthread_mutex_unlock(&(*philosopher)->data->forks[(*philosopher)->philo_nbr]);
}

void	sleeping(t_philosophers **philosopher)
{
	gettimeofday(&((*philosopher)->data->curr_time), NULL);
	printf("%ld %d is sleeping\n", (*philosopher)->data->curr_time.tv_usec - (*philosopher)->data->time, (*philosopher)->philo_nbr);
	usleep((*philosopher)->data->time_to_sleep);
}