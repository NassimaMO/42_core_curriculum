#include "philosopher.h"

void	taking_a_fork(t_philosophers **philosopher)
{
	t_philosophers	*tmp;
	int	left_fork;

	tmp = (*(*philosopher)->philosophers_again);
	left_fork = 1;
    //printf("philo = %d\n", (*philosopher)->philo_nbr);
	while (1)
	{
		if (!(*philosopher)->forks)
		{
			(*philosopher)->forks = 1;
			gettimeofday(&((*philosopher)->philo.curr_time), NULL);
			printf("%ld %d has taken a fork\n", (*philosopher)->philo.curr_time.tv_usec - (*philosopher)->philo.time, (*philosopher)->philo_nbr);
			break ;
		}
	}
	while (left_fork)
	{
		if ((*philosopher)->philo_nbr == (*philosopher)->philo.number_of_philosophers \
			&& tmp->philo_nbr == 1 && !tmp->forks)
		{
			left_fork = 0;
			tmp->forks = 1;
			gettimeofday(&(tmp->philo.curr_time), NULL);
			printf("%ld %d has taken a fork (2)\n", tmp->philo.curr_time.tv_usec - tmp->philo.time, (*philosopher)->philo_nbr);
            break;
		}
		else if (tmp->philo_nbr == (*philosopher)->philo_nbr + 1 && !tmp->forks)
		{
			left_fork = 0;
			tmp->forks = 1;
			gettimeofday(&(tmp->philo.curr_time), NULL);
			printf("%ld %d has taken a fork (2)\n", tmp->philo.curr_time.tv_usec - tmp->philo.time, (*philosopher)->philo_nbr);
            break;
		}
        if (tmp->philo_nbr == tmp->philo.number_of_philosophers)
	        tmp = (*(*philosopher)->philosophers_again);
        else
		    tmp = tmp->next;
	}
}

void	eating(t_philosophers **philosopher)
{
	t_philosophers	*tmp;

	tmp = (*(*philosopher)->philosophers_again);
	(*philosopher)->forks = 0;
	if ((*philosopher)->philo_nbr == (*philosopher)->philo.number_of_philosophers)
		tmp->forks = 0;
	else
	{
		while (tmp->philo_nbr < (*philosopher)->philo_nbr + 1)
			tmp = tmp->next;
		tmp->forks = 0;
	}
	gettimeofday(&(tmp->philo.curr_time), NULL);
	printf("%ld %d is eating\n", tmp->philo.curr_time.tv_usec - (*philosopher)->philo.time, (*philosopher)->philo_nbr);
	(*philosopher)->last_eaten = tmp->philo.curr_time.tv_usec - (*philosopher)->philo.time;
	(*philosopher)->nbr_of_times_a_philo_has_eaten++;
	usleep((*philosopher)->philo.time_to_eat);
}

void	thinking(t_philosophers **philosopher) 
{
    /*printf("philo_num = %d\n", (*philosopher)->philo_nbr);
	printf("nbr_philo = %d\n", (*philosopher)->philo.number_of_philosophers);
	printf("time = %ld\n", (*philosopher)->philo.time);
	printf("time_to_die = %d\n", (*philosopher)->philo.time_to_die);
	printf("time_to_eat = %d\n", (*philosopher)->philo.time_to_eat);
	printf("time_to_sleep = %d\n", (*philosopher)->philo.time_to_sleep);
	printf("notapme = %d\n\n\n\n\n\n\n\n", (*philosopher)->philo.nbr_of_times_a_philo_must_eat);*/
	gettimeofday(&((*philosopher)->philo.curr_time), NULL);
	printf("%ld %d is thinking\n", (*philosopher)->philo.curr_time.tv_usec - (*philosopher)->philo.time, (*philosopher)->philo_nbr);
}

void	sleeping(t_philosophers **philosopher)
{
	gettimeofday(&((*philosopher)->philo.curr_time), NULL);
	printf("%ld %d is sleeping\n", (*philosopher)->philo.curr_time.tv_usec - (*philosopher)->philo.time, (*philosopher)->philo_nbr);
	usleep((*philosopher)->philo.time_to_sleep);
}

int	dying(t_philosophers **philosopher)
{
	gettimeofday(&((*philosopher)->philo.curr_time), NULL);
	if (((*philosopher)->philo.curr_time.tv_usec - (*philosopher)->philo.time) - (*philosopher)->last_eaten >= (*philosopher)->philo.time_to_die)
		return (printf("%ld %d died\n", (*philosopher)->philo.curr_time.tv_usec - (*philosopher)->philo.time, (*philosopher)->philo_nbr), 1);
	return (0);
}

void	*routine(void *philosopher)
{
	while(1)
	{
		thinking(((t_philosophers **)philosopher));
		pthread_mutex_lock(&(((t_philosophers *)philosopher)->philo.mutex));
		taking_a_fork(((t_philosophers **)philosopher));
		pthread_mutex_unlock(&(((t_philosophers *)philosopher)->philo.mutex));
		pthread_mutex_lock(&(((t_philosophers *)philosopher)->philo.mutex));
		eating(((t_philosophers **)philosopher));
		pthread_mutex_unlock(&(((t_philosophers *)philosopher)->philo.mutex));
		sleeping(((t_philosophers **)philosopher));
		if (dying(((t_philosophers **)philosopher)))
			(ft_lstclear((*(t_philosophers **)philosopher)->philosophers_again),  exit(1));
		if (((t_philosophers *)philosopher)->nbr_of_times_a_philo_has_eaten == ((t_philosophers *)philosopher)->philo.nbr_of_times_a_philo_must_eat - 1)
			return NULL;
	}
}

void	create_list(t_philosophers **philosophers, t_philo philo)
{
	int			i;
	t_philosophers	*tmp;
	t_philosophers	*last_tmp;

	tmp = malloc(sizeof(t_philosophers));
	tmp->philo_nbr = 1;
	tmp->forks = 0;
	tmp->last_eaten = 0;
	tmp->nbr_of_times_a_philo_has_eaten = 0;
	tmp->philo = philo;
	*philosophers = tmp;
	tmp->philosophers_again = philosophers;
	last_tmp = tmp;
	tmp = tmp->next;
	i = 0;
	while (++i < philo.number_of_philosophers)
	{
		tmp = malloc(sizeof(t_philosophers));
		tmp->philo_nbr = i + 1;
		tmp->forks = 0;
		tmp->last_eaten = 0;
		tmp->nbr_of_times_a_philo_has_eaten = 0;
		tmp->philo = philo;
		tmp->philosophers_again = philosophers;
		last_tmp->next = tmp;
		last_tmp = tmp;
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_philosophers	*philosophers;
	t_philo			*philo;
	t_philosophers  *tmp;
	struct timeval	time;
	pthread_mutex_t	mutex;
	int				i;

	if (argc < 5 || argc > 6)
		return (1);
	pthread_mutex_init(&mutex, NULL);
	philo = malloc(sizeof(t_philo));
	philo->mutex = mutex;
	pthread_mutex_lock(&(philo->mutex));
	philo->number_of_philosophers = atoi(argv[1]);
	philo->time_to_die = atoi(argv[2]);
	philo->time_to_eat = atoi(argv[3]);
	philo->time_to_sleep = atoi(argv[4]);
		pthread_mutex_unlock(&(philo->mutex));
	philo->nbr_of_times_a_philo_must_eat = -1;
	if (argc == 6)
		philo->nbr_of_times_a_philo_must_eat = atoi(argv[5]);
	if (philo->time_to_sleep < 60 || philo->time_to_eat < 60)
		return (0);
	create_list(&philosophers, *philo);
	tmp = philosophers;
	gettimeofday(&time, NULL);
	i = -1;
	while (++i < philosophers->philo.number_of_philosophers)
	{
		tmp->philo.time = time.tv_usec;
		tmp->last_eaten = time.tv_usec;
		pthread_create(&tmp->thread, NULL, routine, &tmp);
		tmp = tmp->next;
	}
	tmp = philosophers;
	i = -1;
	while (++i < philosophers->philo.number_of_philosophers)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
	}
    free(philo);
    ft_lstclear(&philosophers);
	pthread_mutex_destroy(&philo->mutex);
}