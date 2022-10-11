/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:06:18 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/11 14:37:13 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}				t_stacks;

/*typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
}	t_stack;*/

int				number_checker(char **argv, int argc);
int				verif_double(char *a, char **argv, int argc, int x);
long long int	nbr_to_str(char *a);
int				*put_int_tab(char **argv, int argc);

void			rev_scase(t_stacks *stacks);

int				num_max(int x, int *ab, int len);
int				num_min(int x, int *ab, int len);
void			ft_sort_int_tab(int *tab, int size);
int				*ft_dup(const int *a, int len);
int				nums_in_order_rev(int *ab, int len);
int				nums_in_order(t_stacks *stacks, int x, int y);

#endif
