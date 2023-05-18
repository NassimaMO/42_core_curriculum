#include "../includes/philo_lib.h"

int main(int argc, char **argv)
{
    int			i;
	int			*pid;
    t_data		data;
    pthread_t	*threads;

    if (verif(argc, argv))
        return (1);
    init_data(&data, argc, argv);
    threads = malloc(data.total_philos * sizeof(pthread_t));
	pid = malloc((data.total_philos + 1) * sizeof(pthread_t));
	i = 0;
    while (i < data.total_philos)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			data.philo_nbr = i + 1;
			if (creating_threads(threads[i], &data) < 0)
				printf("An error occured while trying to create the thread of philo number %d...\n", data.philo_nbr), sem_post(data.sync_sem);
			sem_close(data.forks_sem);
			sem_close(data.print_sem);
			sem_close(data.dead_sem);
			sem_close(data.stop_sem);
			sem_close(data.sync_sem);
			sem_close(data.eaten_sem);
			exit(0);
		}
		if (i == data.total_philos - 1)
			sem_post(data.sync_sem);
		i++;
	}
	if (data.nbr_of_times_a_philo_must_eat >= 0)
	{
		i = 0;
		while (i < data.total_philos)
		{
			sem_wait(data.eaten_sem);
			i++;
		}
		sem_wait(data.print_sem);
		i = 0;
		while (i < data.total_philos)
		{
			sem_post(data.dead_sem);
			i++;
		}
		sem_post(data.print_sem);
	}
	i = 0;
	while (i < data.total_philos)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
	free(threads);
	free(pid);
	return (0);
}
