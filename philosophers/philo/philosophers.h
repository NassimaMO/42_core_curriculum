#ifndef PHILOSOPHERS_H
# define PHILOSPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define INT_MAX 2147483647

typedef struct	s_data
{
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	int				philo_stop;
	int				number_of_philosophers;
	long int		time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_times_a_philo_must_eat;
}				t_data;

typedef struct	s_philosophers
{
	int						philo_nbr;
	pthread_t				thread;
	long int				last_eaten;
	int						wait;
	int						nbr_of_times_a_philo_has_eaten;
	t_data					*data;
	struct s_philosophers	*next;
}				t_philosophers;

int			arg_verif(int argc, char **argv);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

void		printing_philo(t_philosophers **philosopher);
void		printing_list(t_philosophers *philosophers);

void		creat_list(t_philosophers **philosophers, t_data *data);
int			stock_data(t_data *data, int argc, char **argv);

long int	current_time(void);
void		ft_usleep(t_philosophers **philosopher, long int time_to_do_smth);
void		print_lock(t_philosophers **philosopher, char *current_activity, long int time);
int			dying(t_philosophers **philosopher);
void		eating(t_philosophers **philosopher);

void		free_data(t_data *data);
void		free_list(t_philosophers **philosophers);
void		free_thread(t_philosophers *philosopher);

#endif