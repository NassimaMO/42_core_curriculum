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

int number_checker(char **argv, int argc);
int verif_double(char *a, char **argv, int x);
long long int nbr_to_str(char *a);
int *put_int_tab(char **argv, int argc);

void algo_op(int *a, int *b, int ac);

void super_algo_op3(int *a, int *b, int ac);

int num_max(int x, int *ab, int len);
int num_min(int x, int *ab, int len);
int find_num_min(int *ab, int len);
int find_num_max(int *ab, int len);
int	find_num(int *ab, int x, int len);
int nums_in_order(t_stacks *stacks, int x, int y);
int *next_max_stack(t_stacks *stacks);
void	ft_bzero(void *s, size_t n);

void pab(int *ab, int *ba, int len_ab, int len_ba);
void rab(int *ab, int len_ba);
void rr(int *a, int *b, int len_a, int len_b);
void rrab(int *ab, int len_ab);
void rrr(int *a, int *b, int len_a, int len_b);
void sab(int *ab);
void ss(int *a, int *b);

#endif
