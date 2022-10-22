#include "philosopher.h"

void	*routine(void *philosopher)
{
	static int	i;
	pthread_mutex_t	mutex;
	struct timeval	time;

	pthread_mutex_lock(&mutex);
	gettimeofday(&time, NULL);
	if (i == 0)
		((t_philo *)philosopher)->time = time.tv_usec;
	//take_a_fork();
	printf("%ld %d has taken a fork\n", time.tv_usec - ((t_philo *)philosopher)->time, i + 1);
	//eat();
	printf("%ld %d is eating\n", time.tv_usec - ((t_philo *)philosopher)->time, i + 1);
	//think();
	printf("%ld %d is thinking\n", time.tv_usec - ((t_philo *)philosopher)->time, i + 1);
	//sleep();
	printf("%ld %d is sleeping\n", time.tv_usec - ((t_philo *)philosopher)->time, i + 1);
	//die();
	printf("%ld %d died\n", time.tv_usec - ((t_philo *)philosopher)->time, i + 1);
	i++;
	pthread_mutex_unlock(&mutex);
}

int	main(int argc, char **argv)
{
	pthread_t	thread_one[atoi(argv[1])];
	pthread_mutex_t	mutex_one[atoi(argv[1])];
	t_philo		philosopher;
	int			i;

	if (argc < 5 || argc > 6)
		return (1);
	philosopher.time = 0;
	philosopher.threads = thread_one;
	philosopher.mutex = mutex_one;
	philosopher.number_of_philosophers = atoi(argv[1]);
	philosopher.time_to_die = atoi(argv[2]);
	philosopher.time_to_eat = atoi(argv[3]);
	philosopher.time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		philosopher.nbr_of_times_a_philo_must_eat = atoi(argv[5]);
	if (philosopher.time_to_die < 60 || philosopher.time_to_eat < 60)
		return (0);
	i = -1;
	while (++i < philosopher.number_of_philosophers)
		pthread_create(&(philosopher.threads[i]), NULL, routine, &philosopher);
	i = -1;
	while (++i < philosopher.number_of_philosophers)
		pthread_join(philosopher.threads[i], NULL);
}