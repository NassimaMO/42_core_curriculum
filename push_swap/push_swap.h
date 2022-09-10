/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:06:18 by nmouslim          #+#    #+#             */
/*   Updated: 2022/07/04 19:06:20 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stacks
{
	int *a;
	int *b;
	int len_a;
	int len_b;
} t_stacks;

int				number_checker(char **argv, int argc);
int				verif_double(char *a, char **argv, int argc, int x);
long long int	nbr_to_str(char *a);
int				*put_int_tab(char **argv, int argc);

void			algo_op(t_stacks *stacks);
void			super_algo_op3(t_stacks *stacks);
void			twilio_algo(t_stacks *stacks);

void			rev_scase(t_stacks *stacks);

int				num_max(int x, int *ab, int len);
int				num_min(int x, int *ab, int len);
void			ft_sort_int_tab(int *tab, int size);
int				*ft_dup(const int *a, int len);
int				nums_in_order_rev(int *ab, int len);
int				nums_in_order(t_stacks *stacks, int x, int y);

void			pab(int *ab, int *ba, int len_ab, int len_ba);
void			rab(int *ab, int len_ba);
void			rr(int *a, int *b, int len_a, int len_b);
void			rrab(int *ab, int len_ab);
void			rrr(int *a, int *b, int len_a, int len_b);
void			sab(int *ab);
void			ss(int *a, int *b);

#endif
