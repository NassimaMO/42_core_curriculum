#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"
#include "semaphore.h"
#include "time.h"
#include "sys/wait.h"
#include "unistd.h"
#include "fcntl.h"

typedef struct s_data
{
	sem_t			*print;
	int				philo;
}              t_data;

t_data	*stock_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->print = sem_open("/print", O_CREAT | O_EXCL, 0644, 0);
	data->philo = 0;
	return (data);
}

void	free_data(t_data *data)
{
	sem_close(data->print);
	free(data);
}

void *routine(void *data)
{
	printf("%ld.\n", ((t_data *)data)->print->__align);
    sem_wait(((t_data *)data)->print);
    printf("%d\n", ((t_data *)data)->philo++);
    sleep(3);
    sem_post(((t_data *)data)->print);
}

int	create_process(pthread_t thread, t_data *data, int pid)
{
	printf("no\n");
	if (pid == 0)
    {
		printf("philo=%d\n", data->philo++);
		printf("repeat=%d.\n", data->philo);
        /*if (pthread_create(&thread, NULL, routine, data))
            return (1);
        if (pthread_join(thread, NULL))
            return (2);*/
    }
	return (0);
}

int main(int argc, char **argv)
{
    t_data          *data;
    pthread_t		thread1;
    pthread_t		thread2;
	int				pid;

    data = stock_data(argc, argv);
	pid = fork();
	create_process(thread1, data, pid);
	if (pid > 0)
		pid = fork(), create_process(thread2, data, pid);
	waitpid(-1, NULL, 0);
    free_data(data);
}