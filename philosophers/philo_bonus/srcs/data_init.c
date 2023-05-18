#include "../includes/philo_lib.h"

void	init_data(t_data *data, int argc, char **argv)
{
	data->total_philos = atoi(argv[1]);
	sem_unlink("/print_sem");
	sem_unlink("/forks_sem");
	sem_unlink("/dead_sem");
	sem_unlink("/stop_sem");
    sem_unlink("/sync_sem");
	sem_unlink("/eaten_sem");
    data->sync_sem = sem_open("/sync_sem", O_CREAT, 0644, 0);
	data->print_sem = sem_open("/print_sem", O_CREAT, 0644, 1);
	data->forks_sem = sem_open("/forks_sem", O_CREAT, 0644, \
	data->total_philos);
	data->eaten_sem = sem_open("/eaten_sem", O_CREAT, 0644, 0);
	data->dead_sem = sem_open("/dead_sem", O_CREAT, 0644, 0);
	data->stop_sem = sem_open("/stop_sem", O_CREAT, 0644, 1);
	data->stop = 0;
	data->nbr_of_times_a_philo_has_eaten = 0;
	data->time = 0;
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	data->nbr_of_times_a_philo_must_eat = -1;
	if (argc == 6)
		data->nbr_of_times_a_philo_must_eat = atoi(argv[5]);
}