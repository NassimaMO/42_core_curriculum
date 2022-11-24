#include "philosophers.h"

void	*routine(void *philosopher)
{
	t_philosophers	*tmp;

	tmp = (t_philosophers *)philosopher;
	if (tmp->philo_nbr % 2 == 0)
		usleep(10);
	tmp->last_eaten = current_time();
	while (!dying(&tmp))
	{
		eating(&tmp);
		print_lock(&tmp, "is sleeping", current_time());
		print_lock(&tmp, "is thinking", current_time());
		usleep(tmp->data->time_to_sleep);
		if ((tmp->data->nbr_of_times_a_philo_must_eat >= 0 && tmp->nbr_of_times_a_philo_has_eaten >= tmp->data->nbr_of_times_a_philo_must_eat))
			return (NULL);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philosophers	*philosophers;
	t_philosophers	*tmp;
	int				i;
	t_data			*data;

	if (arg_verif(argc, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (stock_data(data, argc, argv))
		return (1);
	creat_list(&philosophers, data);
	tmp = philosophers;
	i = -1;
	while (++i < philosophers->data->number_of_philosophers)
	{
		if (i == 0)
			tmp->data->time = current_time();
		pthread_create(&tmp->thread, NULL, routine, tmp);
		tmp = tmp->next;
	}
	tmp = philosophers;
	i = -1;
	while (++i < philosophers->data->number_of_philosophers)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
	}
	free_list(&philosophers);
}
