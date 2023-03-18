#include "new_philo.h"

int	dying(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->infos);
	if (data->philo_stop >= data->number_of_philosophers)
		return (pthread_mutex_unlock(&data->infos), 1);
	pthread_mutex_unlock(&data->infos);
	if (data->number_of_philosophers == 1)
		usleep(data->time_to_die * 1000);
	if (current_time() - philo->last_eaten >= data->time_to_die)
	{
		print_lock(philo, data, "died");
		pthread_mutex_lock(&data->infos);
		data->philo_stop = data->number_of_philosophers;
		pthread_mutex_unlock(&data->infos);
		return (1);
	}
	return (0);
}

static void	lock_fork(t_philo *philo, t_data *data)
{
	if (philo->philo_nbr % 2 > 0)
	{
		pthread_mutex_lock(&data->forks[philo->philo_nbr - 1]);
		print_lock(philo, data, "has taken a fork");
		if (philo->philo_nbr == data->number_of_philosophers)
			pthread_mutex_lock(&data->forks[0]);
		else
			pthread_mutex_lock(&data->forks[philo->philo_nbr]);
		print_lock(philo, data, "has taken a fork");
	}
	else
	{
		if (philo->philo_nbr == data->number_of_philosophers)
			pthread_mutex_lock(&data->forks[0]);
		else
			pthread_mutex_lock(&data->forks[philo->philo_nbr]);
		print_lock(philo, data, "has taken a fork");
		pthread_mutex_lock(&data->forks[philo->philo_nbr - 1]);
		print_lock(philo, data, "has taken a fork");
	}
}

static void	unlock_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_unlock(&data->forks[philo->philo_nbr - 1]);
	if (philo->philo_nbr == data->number_of_philosophers)
		pthread_mutex_unlock(&data->forks[0]);
	else
		pthread_mutex_unlock(&data->forks[philo->philo_nbr]);
}

void	eating(t_philo *philo, t_data *data)
{
	lock_fork(philo, data);
	print_lock(philo, data, "is eating");
	philo->last_eaten = current_time();
	ft_usleep(philo, data, data->time_to_eat);
	if (data->nbr_of_times_a_philo_must_eat >= 0)
		philo->nbr_of_times_a_philo_has_eaten++;
	unlock_fork(philo, data);
}