#include "philosophers.h"

void	printing_philo(t_philosophers **philosopher)
{
	printf("\n\n\n\n\n\n\n|||||||||||||||||||||||||||||P number = %d|||||||||||||||||||||||||||||||||\n", (*philosopher)->philo_nbr);
	printf("|||||||||||||                                                |||||||||||||\n");
	printf("||||||||||||| data struct infos:                             |||||||||||||\n");
	printf("|||||||||||||                                                |||||||||||||\n");
	printf("||||||||||||| times P should eat = %d;                       |||||||||||||\n", (*philosopher)->data->nbr_of_times_a_philo_must_eat);
	printf("||||||||||||| number of P = %d;                               |||||||||||||\n", (*philosopher)->data->number_of_philosophers);
	printf("||||||||||||| time = %ld;                                 |||||||||||||\n", (*philosopher)->data->time);
	printf("||||||||||||| time to die = %d;                             |||||||||||||\n", (*philosopher)->data->time_to_die);
	printf("||||||||||||| time to eat = %d;                             |||||||||||||\n", (*philosopher)->data->time_to_eat);
	printf("||||||||||||| time to sleep = %d.                           |||||||||||||\n", (*philosopher)->data->time_to_sleep);
	printf("|||||||||||||                                                |||||||||||||\n");
	printf("||||||||||||| personal P infos:                              |||||||||||||\n");
	printf("|||||||||||||                                                |||||||||||||\n");
	printf("||||||||||||| last_eaten = %ld;                           |||||||||||||\n", (*philosopher)->last_eaten);
	printf("||||||||||||| has eaten = %d times.                           |||||||||||||\n", (*philosopher)->nbr_of_times_a_philo_has_eaten);
	printf("|||||||||||||                                                |||||||||||||\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n\n\n\n\n\n\n");
}

void    printing_list(t_philosophers *philosophers)
{
	t_philosophers	*tmp;
	int				i;

	tmp = philosophers;
	i = -1;
	while (++i < philosophers->data->number_of_philosophers)
	{
		printing_philo(&tmp);
		tmp = tmp->next;
	}
}