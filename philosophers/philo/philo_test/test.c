# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_mutex_t	mutex;
	int				num;
}				t_data;

void    *routine(void *struc)
{
	t_data	*data;

	data = (t_data *)struc;
	pthread_mutex_lock(&data->mutex);
	data->num++;
	pthread_mutex_unlock(&data->mutex);
	if (data->num % 2 > 0)
		usleep(20);
	return (NULL);
}

int     main(int argc, char **argv)
{
	int		num_threads = atoi(argv[1]);
	pthread_t	threads[num_threads + 1];
	t_data	data;
	int		i;

	i = 0;
	data.num = 0;
	pthread_mutex_init(&data.mutex, NULL);
	while (i < num_threads)
	{
		if (pthread_create(&threads[i], NULL, routine, &data))
			return (1);
/* 		data.num++;
 */		if (pthread_join(threads[i], NULL))
			return (2);
		i++;
	}
	pthread_mutex_destroy(&data.mutex);
	printf("The number was increased to %d.\n", data.num);
	return (0);
}