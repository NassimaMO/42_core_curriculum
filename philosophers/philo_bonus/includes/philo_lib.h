/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:27:45 by nmouslim          #+#    #+#             */
/*   Updated: 2023/05/27 16:27:48 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_LIB_H
# define PHILO_LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <sys/wait.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/time.h>

typedef struct s_data
{
	sem_t			*dead_sem;
	sem_t			*print_sem;
	sem_t			*forks_sem;
	sem_t			*stop_sem;
	sem_t			*eaten_sem;
	sem_t			*last_eat_sem;
	int				stop;
	int				philo_nbr;
	long int		last_eaten;
	int				nbr_of_times_a_philo_has_eaten;
	long int		time;
	int				total_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_times_a_philo_must_eat;
}				t_data;

int			verif(int argc, char **argv);
void		init_data(t_data *data, int argc, char **argv);
int			creating_threads(pthread_t thread, t_data *data);
long int	current_time(void);
int			ft_usleep(t_data *data, long int time_to_do_smth);
void		print_lock(t_data *data, char *current_activity);
int			dying(t_data *data);
int			eating(t_data *data);
int			ft_atoi(const char *nptr);

#endif
