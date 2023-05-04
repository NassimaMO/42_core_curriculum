/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:35:15 by nmouslim          #+#    #+#             */
/*   Updated: 2023/03/19 16:35:16 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/signal.h>

# define INT_MAX 2147483647

typedef struct s_data
{
	sem_t			*die;
	sem_t			*print;
	sem_t			*forks;
	sem_t			*sem_stop;
	int				philo_nbr;
	long int		last_eaten;
	int				stop;
	int				nbr_of_times_a_philo_has_eaten;
	long int		time;
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_times_a_philo_must_eat;
}				t_data;

/* new_philo_check.c */
int			arg_verif(int argc, char **argv);

/* new_philo_init.c */
int			stock_data(t_data *data, int argc, char **argv);

/* new_philo_threads.c */
void		*routine(void *struc);
void		*philo_routine(t_data *data);

/* new_philo_doing_things.c */
int			dying(t_data *data);
void		eating(t_data *data);

/* new_philo_utils.c */
long int	current_time(void);
void		ft_usleep(t_data *data, long int time_to_do_smth);
void		print_lock(t_data *data, char *current_activity);

/* new_philo_free.c */
void		free_data(t_data *data);

#endif
