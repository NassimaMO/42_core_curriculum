#include "philosopher.h"

int	taking_a_fork(t_philo *philosopher, int i, struct timeval time)
{
	if (i == philosopher->number_of_philosophers - 1 && \
		!philosopher->forks[0] && !philosopher->forks[philosopher->number_of_philosophers - 1])
	{
		philosopher->forks[philosopher->number_of_philosophers - 1] =  1;
		gettimeofday(&time, NULL);
		printf("%ld %d has taken a fork\n", time.tv_usec - philosopher->time, i + 1);
		philosopher->forks[0] = 1;
		gettimeofday(&time, NULL);
		printf("%ld %d has taken a fork\n", time.tv_usec - philosopher->time, i + 1);
		return (1);
	}
	else if (!philosopher->forks[i + 1] && !philosopher->forks[i])
	{
		philosopher->forks[i + 1] =  1;
		gettimeofday(&time, NULL);
		printf("%ld %d has taken a fork\n", time.tv_usec - philosopher->time, i + 1);
		philosopher->forks[i] = 1;
		gettimeofday(&time, NULL);
		printf("%ld %d has taken a fork\n", time.tv_usec - philosopher->time, i + 1);
		return (1);
	}
	return (0);
}

void	eating(t_philo *philosopher, int i, struct timeval time)
{
	if (i == philosopher->number_of_philosophers - 1 && \
		philosopher->forks[0] && philosopher->forks[philosopher->number_of_philosophers - 1])
	{
		philosopher->forks[philosopher->number_of_philosophers - 1] =  0;
		philosopher->forks[0] = 0;
		gettimeofday(&time, NULL);
		printf("%ld %d is eating\n", time.tv_usec - philosopher->time, i + 1);
		philosopher->last_eaten[i] = time.tv_usec - philosopher->time;
		usleep(philosopher->time_to_eat);
	}
	else if (philosopher->forks[i + 1] && philosopher->forks[i])
	{
		philosopher->forks[i + 1] =  0;
		philosopher->forks[i] = 0;
		gettimeofday(&time, NULL);
		printf("%ld %d is eating\n", time.tv_usec - philosopher->time, i + 1);
		philosopher->last_eaten[i] = time.tv_usec - philosopher->time;
		usleep(philosopher->time_to_eat);
	}
}

void	thinking(t_philo *philosopher, int i, struct timeval time) 
{
	gettimeofday(&time, NULL);
	printf("%ld %d is thinking\n", time.tv_usec - philosopher->time, i + 1);
}

void	sleeping(t_philo *philosopher, int i, struct timeval time)
{
	gettimeofday(&time, NULL);
	printf("%ld %d is sleeping\n", time.tv_usec - philosopher->time, i + 1);
	usleep(philosopher->time_to_sleep);
}

int	dying(t_philo *philosopher, int i, struct timeval time)
{
	gettimeofday(&time, NULL);
	if ((time.tv_usec - philosopher->time) - philosopher->last_eaten[i] >= philosopher->time_to_die)
		return (printf("%ld %d died\n", time.tv_usec - philosopher->time, i + 1), 1);
	return (0);
}

void	*routine(void *philosopher)
{
	static int	i;
	static int	x;
	struct timeval	time;

	while(!dying(philosopher, i, time))
	{
		pthread_mutex_lock(&(((t_philo *)philosopher)->mutex));
		if (x == 0)
		{
			gettimeofday(&time, NULL);
			((t_philo *)philosopher)->time = time.tv_usec;
			x = -1;
			while (++x < ((t_philo *)philosopher)->number_of_philosophers)
				((t_philo *)philosopher)->last_eaten[x] = time.tv_usec;
			x = 0;
		}
		if (taking_a_fork(philosopher, i, time))
			eating(philosopher, i, time);
		thinking(philosopher, i, time);
		sleeping(philosopher, i, time);
		if (x == ((t_philo *)philosopher)->nbr_of_times_a_philo_must_eat - 1)
			exit(1);
		i++;
		x++;
		if (i == ((t_philo *)philosopher)->number_of_philosophers - 1)
			i = 0;
		pthread_mutex_unlock(&(((t_philo *)philosopher)->mutex));
	}
}

int	main(int argc, char **argv)
{
	t_philo		philosopher;
	int			i;

	if (argc < 5 || argc > 6)
		return (1);
	philosopher.threads = malloc(atoi(argv[1]) * sizeof(pthread_t));
	pthread_mutex_init(&philosopher.mutex, NULL);
	philosopher.number_of_philosophers = atoi(argv[1]);
	philosopher.forks = malloc(philosopher.number_of_philosophers * sizeof(int));
	philosopher.last_eaten = malloc(philosopher.number_of_philosophers * sizeof(long int));
	i = -1;
	while (++i < philosopher.number_of_philosophers)
	{
		philosopher.forks[i] = 0;
		philosopher.last_eaten[i] = 0;
	}
	philosopher.time_to_die = atoi(argv[2]);
	philosopher.time_to_eat = atoi(argv[3]);
	philosopher.time_to_sleep = atoi(argv[4]);
	philosopher.nbr_of_times_a_philo_must_eat = -1;
	if (argc == 6)
		philosopher.nbr_of_times_a_philo_must_eat = atoi(argv[5]);
	if (philosopher.time_to_sleep < 60 || philosopher.time_to_eat < 60)
		return (0);
	i = -1;
	while (++i < philosopher.number_of_philosophers)
		pthread_create(&(philosopher.threads[i]), NULL, routine, &philosopher);
	i = -1;
	while (++i < philosopher.number_of_philosophers)
		pthread_join(philosopher.threads[i], NULL);
	free(philosopher.forks);
	free(philosopher.last_eaten);
	free(philosopher.threads);
	pthread_mutex_destroy(&philosopher.mutex);
}