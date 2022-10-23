#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philo
{
	pthread_t		*threads;
	pthread_mutex_t	mutex;
	int				number_of_philosophers;
	int				*forks;
	long int		*last_eaten;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_times_a_philo_must_eat;
	long int		time;
}				t_philo;

#endif