#include "../includes/philo_lib.h"

// in the dying function do not forget to post the eaten_sems if nbr_of_times_a_philo_must_eat is equal or superior to 0.

int	dying(t_data *data)
{
	int	i;

	/*if (data->nbr_philos == 1)
		usleep(data->time_to_die * 1000);*/
	sem_wait(data->stop_sem);
	if (current_time() - data->last_eaten >= data->time_to_die)
	{
		sem_wait(data->print_sem);
		if (!data->stop)
		{
			printf("%ld %d %s\n", current_time() - data->time, \
				data->philo_nbr, "died");
			if (data->nbr_of_times_a_philo_must_eat >= 0)
			{
				i = 0;
				while (i < data->total_philos)
				{
					sem_post(data->eaten_sem);
					i++;
				}
			}
			else
            {
				i = 0;
				while (i < data->total_philos)
				{
					sem_post(data->dead_sem);
					i++;
				}
			}
			sem_post(data->print_sem);
			sem_post(data->stop_sem);
			return (1);
		}
		sem_post(data->print_sem);
	}
	if (data->stop)
	{
		sem_post(data->stop_sem);
		return (1);
	}
	sem_post(data->stop_sem);
	return (0);
}

static void	lock_fork(t_data *data)
{
	sem_wait(data->forks_sem);
	sem_wait(data->forks_sem);
	print_lock(data, "has taken a fork");
	print_lock(data, "has taken a fork");
}

static void	unlock_fork(t_data *data)
{
	sem_post(data->forks_sem);
	sem_post(data->forks_sem);
}

int	eating(t_data *data)
{
	lock_fork(data);
	print_lock(data, "is eating");
	sem_wait(data->stop_sem);
	data->last_eaten = current_time();
	sem_post(data->stop_sem);
	if (ft_usleep(data, data->time_to_eat) && (unlock_fork(data), 1))
		return (1);
	if (data->nbr_of_times_a_philo_must_eat >= 0)
		data->nbr_of_times_a_philo_has_eaten++;
	unlock_fork(data);
	return (0);
}