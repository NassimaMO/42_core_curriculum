#include "philosophers.h"

void	*routine(void *philosopher)
{
	t_philosophers	**tmp;

	tmp = (t_philosophers **)philosopher;
	while (!dying(tmp))
	{
		printing_philo(philosopher);
		thinking(tmp);
		printing_philo(philosopher);
		eating(tmp);
		printing_philo(philosopher);
		sleeping(tmp);
		printing_philo(philosopher);
		if (((t_philosophers *)philosopher)->nbr_of_times_a_philo_has_eaten == ((t_philosophers *)philosopher)->data->nbr_of_times_a_philo_must_eat - 1)
			return (free_thread((t_philosophers *)philosopher), NULL);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philosophers	*philosophers;
	t_philosophers	*tmp;
	int				i;
	t_data			*data;

	if (argc < 5 || argc > 6)
		return (1);
	data = malloc(sizeof(t_data));
	if (stock_data(data, argc, argv))
		return (1);
	creat_list(&philosophers, data);
	tmp = philosophers;
	gettimeofday(&philosophers->data->curr_time, NULL);
	i = -1;
	while (++i < philosophers->data->number_of_philosophers)
	{
		tmp->data->time = philosophers->data->curr_time.tv_usec;
		tmp->last_eaten = philosophers->data->curr_time.tv_usec;
		pthread_create(&tmp->thread, NULL, routine, &tmp);
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