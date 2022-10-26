#include "philosopher.h"

void	taking_a_fork(t_philosophers *philosopher)
{
	t_philosophers	*tmp;
	int	left_fork;

	tmp = ((t_philosophers *)philosopher->philosophers_again);
	left_fork = 1;
	while (1)
	{
		if (!philosopher->forks)
		{
			philosopher->forks = 1;
			gettimeofday(&tmp->philo->curr_time, NULL);
			printf("%ld %d has taken a fork\n", tmp->philo->curr_time.tv_usec - tmp->philo->time, philosopher->philo_nbr);
			break ;
		}
	}
	while (left_fork)
	{
		if (philosopher->philo_nbr == philosopher->philo->number_of_philosophers \
			&& tmp->philo_nbr == 1 && !tmp->forks)
		{
			left_fork = 0;
			tmp->forks = 1;
			gettimeofday(&tmp->philo->curr_time, NULL);
			printf("%ld %d has taken a fork\n", tmp->philo->curr_time.tv_usec - tmp->philo->time, philosopher->philo_nbr);
		}
		else if (tmp->philo_nbr == philosopher->philo_nbr + 1 && !tmp->forks)
		{
			left_fork = 0;
			tmp->forks = 1;
			gettimeofday(&tmp->philo->curr_time, NULL);
			printf("%ld %d has taken a fork\n", tmp->philo->curr_time.tv_usec - tmp->philo->time, philosopher->philo_nbr);
		}
		tmp = tmp->next;
	}
}

void	eating(t_philosophers *philosopher)
{
	t_philosophers	*tmp;

	tmp = ((t_philosophers *)philosopher->philosophers_again);
	philosopher->forks = 0;
	if (philosopher->philo_nbr == philosopher->philo->number_of_philosophers)
		tmp->forks = 0;
	else
	{
		while (tmp->philo_nbr < philosopher->philo_nbr + 1)
			tmp = tmp->next;
		tmp->forks = 0;
	}
	gettimeofday(&tmp->philo->curr_time, NULL);
	printf("%ld %d is eating\n", tmp->philo->curr_time.tv_usec - philosopher->philo->time, philosopher->philo_nbr);
	philosopher->last_eaten = tmp->philo->curr_time.tv_usec - philosopher->philo->time;
	philosopher->nbr_of_times_a_philo_has_eaten++;
	usleep(philosopher->philo->time_to_eat);
}

void	thinking(t_philosophers *philosopher) 
{
	gettimeofday(&philosopher->philo->curr_time, NULL);
	printf("%ld %d is thinking\n", philosopher->philo->curr_time.tv_usec - philosopher->philo->time, philosopher->philo_nbr);
}

void	sleeping(t_philosophers *philosopher)
{
	gettimeofday(&philosopher->philo->curr_time, NULL);
	printf("%ld %d is sleeping\n", philosopher->philo->curr_time.tv_usec - philosopher->philo->time, philosopher->philo_nbr);
	usleep(philosopher->philo->time_to_sleep);
}

int	dying(t_philosophers *philosopher)
{
	gettimeofday(&philosopher->philo->curr_time, NULL);
	if ((philosopher->philo->curr_time.tv_usec - philosopher->philo->time) - philosopher->last_eaten >= philosopher->philo->time_to_die)
		return (printf("%ld %d died\n", philosopher->philo->curr_time.tv_usec - philosopher->philo->time, philosopher->philo_nbr), 1);
	return (0);
}

void	*routine(void *philosopher)
{
	struct timeval	time;

	while(1)
	{
		thinking(philosopher);
		//pthread_mutex_lock(&(((t_philo *)philosopher)->mutex));
		taking_a_fork(philosopher);
		//pthread_mutex_unlock(&(((t_philo *)philosopher)->mutex));
		eating(philosopher);
		sleeping(philosopher);
		if (dying(philosopher))
			exit(1);
		if (((t_philosophers *)philosopher)->nbr_of_times_a_philo_has_eaten == ((t_philosophers *)philosopher)->philo->nbr_of_times_a_philo_must_eat - 1)
			return NULL;
	}
}

/*void	create_list(t_philosophers *philosophers, t_philo *philo)
{
	int			i;

	i = -1;
	while (++i < philo->number_of_philosophers)
	{
		tmp = malloc(sizeof(t_philosophers));
		tmp->philo_nbr = i + 1;
		tmp->forks = 0;
		tmp->last_eaten = 0;
		tmp->nbr_of_times_a_philo_has_eaten = 0;
		tmp->philo = philo;
		*tmp->philosophers_again = philosophers;
		tmp = tmp->next;
	}
}*/

int	main(int argc, char **argv)
{
	t_philosophers	philosophers;
	t_philo			*philo;
	t_philosophers  *tmp;
	struct timeval	time;

	if (argc < 5 || argc > 6)
		return (1);
	//pthread_mutex_init(&philo->mutex, NULL);
	philo = malloc(sizeof(t_philo));
	philo->number_of_philosophers = atoi(argv[1]);
	philo->time_to_die = atoi(argv[2]);
	philo->time_to_eat = atoi(argv[3]);
	philo->time_to_sleep = atoi(argv[4]);
	philo->nbr_of_times_a_philo_must_eat = -1;
	if (argc == 6)
		philo->nbr_of_times_a_philo_must_eat = atoi(argv[5]);
	if (philo->time_to_sleep < 60 || philo->time_to_eat < 60)
		return (0);
	//create_list(&philosophers, philo);
	*tmp = philosophers;
	gettimeofday(&time, NULL);
	while (tmp)
	{
		tmp->philo->time = time.tv_usec;
		tmp->last_eaten = time.tv_usec;
		pthread_create(&tmp->thread, NULL, routine, &tmp);
		tmp = tmp->next;
	}
	*tmp = philosophers;
	while (tmp)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
	}
	//free list
	pthread_mutex_destroy(&philo->mutex);
}