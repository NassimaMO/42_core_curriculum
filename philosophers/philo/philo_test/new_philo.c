#include "new_philo.h"

int     main(int argc, char **argv)
{
	int			num_threads = atoi(argv[1]);
	pthread_t	threads[num_threads + 1];
	t_data		data;
	int			i;

	i = 0;
	if (arg_verif(argc, argv))
		return (1);
	if (stock_data(&data, argc, argv))
		return (2);
 	data.time = current_time();
	while (i < num_threads)
	{
		data.test++;
		if (pthread_create(&threads[i], NULL, routine, &data))
			return (3);
		/*pthread_mutex_lock(&data.stop);
		if (data.test == data.number_of_philosophers)
			data.time = current_time();
		pthread_mutex_unlock(&data.stop);*/
		if (pthread_join(threads[i], NULL))
			return (4);
		i++;
	}
	free_data(&data);
	return (0);
}