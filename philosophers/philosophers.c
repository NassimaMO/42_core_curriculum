#include "philosophers.h"

void	free_data(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->meal);
	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->forks[i]);
	free(data->forks);
}

void	free_list(t_philosophers **philosophers)
{
	t_philosophers *tmp;
	int				i;
	int				num;

	num = (*philosophers)->data.number_of_philosophers;
	free_data(&(*philosophers)->data);
	i = -1;
	while (++i < num)
	{
		tmp = *philosophers;
		*philosophers = (*philosophers)->next;
		free(tmp);
	}
}

void	creat_list(t_philosophers **philosophers, t_data data)
{
	int			i;
	t_philosophers	*tmp;
	t_philosophers	*last_tmp;

	tmp = *philosophers;
	tmp->philo_nbr = 1;
	tmp->last_eaten = 0;
	tmp->nbr_of_times_a_philo_has_eaten = 0;
	tmp->data = data;
	*philosophers = tmp;
	last_tmp = tmp;
	tmp = tmp->next;
	i = 0;
	while (++i < data.number_of_philosophers)
	{
		tmp = malloc(sizeof(t_philosophers));
		tmp->philo_nbr = i + 1;
		tmp->last_eaten = 0;
		tmp->nbr_of_times_a_philo_has_eaten = 0;
		tmp->data = data;
		last_tmp->next = tmp;
		last_tmp = tmp;
		tmp = tmp->next;
	}
}

int	stock_data(t_data *data, int argc, char **argv)
{
	int	i;

	pthread_mutex_init(&data->meal, NULL);
	data->number_of_philosophers = atoi(argv[1]);
	data->forks = malloc(data->number_of_philosophers * sizeof(pthread_mutex_t));
	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_mutex_init(&data->forks[i], NULL);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	data->nbr_of_times_a_philo_must_eat = -1;
	if (argc == 6)
		data->nbr_of_times_a_philo_must_eat = atoi(argv[5]);
	if (data->time_to_sleep < 60 || data->time_to_eat < 60)
		return (free_data(data), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philosophers	*philosophers;
	t_philosophers	*tmp;
	t_data			data;

	philosophers = malloc(sizeof(t_philosophers));
	if (argc < 5 || argc > 6)
		return (1);
	if (stock_data(&data, argc, argv))
		return (1);
	creat_list(&philosophers, data);

	/*******************************************************/
	tmp = philosophers;

	while (tmp)
	{
		printf("||||||||||||||||||||||||P number = %d||||||||||||||||||||||||\n\n", tmp->philo_nbr);
		
		printf("data struct infos: \n\n");
		
		//printf("current time = %d ", tmp->data.curr_time);
		printf("times P should eat = %d;\n", tmp->data.nbr_of_times_a_philo_must_eat);
		printf("number of P = %d;\n", tmp->data.number_of_philosophers);
		//printf("time = %ld;\n", tmp->data.time);
		printf("time to die = %d;\n", tmp->data.time_to_die);
		printf("time to eat = %d;\n", tmp->data.time_to_eat);
		printf("time to sleep = %d.\n\n", tmp->data.time_to_sleep);

		printf("personal P infos: \n\n");

		printf("last_eaten = %ld;\n", tmp->last_eaten);
		printf("has eaten = %d times.\n\n", tmp->nbr_of_times_a_philo_has_eaten);

		printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
		tmp = tmp->next;
	}
	/*******************************************************/

	free_list(&philosophers);
}