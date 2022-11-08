#include "philosophers.h"

void	free_data(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->meal);
	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->forks[i]);
	free(data->forks);
	free(data);
}

void	free_list(t_philosophers **philosophers)
{
	t_philosophers *tmp;
	int				i;
	int				num;

	num = (*philosophers)->data->number_of_philosophers;
	free_data((*philosophers)->data);
	tmp = *philosophers;
	i = -1;
	while (++i < num)
	{
		pthread_detach(tmp->thread);
		tmp = tmp->next;
	}
	i = -1;
	while (++i < num)
	{
		tmp = *philosophers;
		*philosophers = (*philosophers)->next;
		free(tmp);
	}
}

void	free_thread(t_philosophers *philosopher)
{
	(void) philosopher;
}