/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:32:32 by nmouslim          #+#    #+#             */
/*   Updated: 2023/03/19 16:32:33 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define INT_MAX 2147483647

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef struct s_data
{
	pthread_mutex_t	infos;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	int				*tab_forks;
	long int		time;
	int				philo_stop;
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_times_a_philo_must_eat;
	int				test;
}				t_data;

typedef struct s_philo
{
	int			philo_nbr;
	long int	last_eaten;
	int			nbr_of_times_a_philo_has_eaten;
	int			philo_odd;
}				t_philo;

/* new_philo_check.c */
int			arg_verif(int argc, char **argv);

/* new_philo_init.c */
int			stock_data(t_data *data, int argc, char **argv);
void		philo_init(t_philo *philo, t_data *data);

/* new_philo_threads.c */
void		*routine(void *struc);
void		*philo_routine(t_philo *philo, t_data *data);

/* new_philo_doing_things.c */
int			dying(t_philo *philo, t_data *data);
int			eating(t_philo *philo, t_data *data);

/* new_philo_utils.c */
long int	current_time(void);
int			ft_usleep(t_philo *philo, t_data *data, long int time_to_do_smth);
void		print_lock(t_philo *philo, t_data *data, char *current_activity);

/* new_philo_free.c */
void		free_data(t_data *data);

#endif
