#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philo
{
	pthread_mutex_t	mutex;
	int				number_of_philosophers;
	long int		time;
	struct timeval	curr_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_times_a_philo_must_eat;
}				t_philo;

typedef struct	s_philosophers
{
	int						philo_nbr;
	pthread_t				thread;
	int						forks;
	long int				last_eaten;
	int						nbr_of_times_a_philo_has_eaten;
	t_philo					*philo;
	struct s_philosophers	*philosophers_again;
	struct s_philosophers	*next;
}				t_philosophers;


#endif