/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:13:02 by nmouslim          #+#    #+#             */
/*   Updated: 2022/11/27 14:49:57 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define INT_MAX 2147483647

typedef struct s_data
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

typedef struct s_philosophers
{
	int						philo_nbr;
	pthread_t				thread;
	long int				last_eaten;
	int						nbr_of_times_a_philo_has_eaten;
	t_data					*data;
	struct s_philosophers	*next;
}				t_philosophers;

int			arg_verif(int argc, char **argv);

void		creat_list(t_philosophers **philos, t_data *data);
int			stock_data(t_data *data, int argc, char **argv);

void		ft_usleep(t_philosophers *philosopher, long int time_to_do_smth);
long int	current_time(void);

void		print_lock(t_philosophers *philo, char *current_activity);
int			dying(t_philosophers *philo);
void		eating(t_philosophers *philo);

void		free_data(t_data *data);
void		free_list(t_philosophers *philos);
void		free_thread(t_philosophers *philos);

#endif
