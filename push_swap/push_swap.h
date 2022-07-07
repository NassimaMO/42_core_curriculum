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
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

# define INT_MAX 2147483647

int				number_checker(char **argv, int argc);
int				verif_double(char *a, char **argv, int x);
long long int	nbr_to_str(char *a);
int				*put_int_tab(char **argv, int argc);

void			algo_op(int *a, int *b, int ac);

void			super_algo_op(int *a, int *b, int ac);

int				num_max(int x, int *ab);
int				num_min(int x, int *ab);
int				num_max_r(int x, int *ab);
int				num_min_r(int x, int *ab);
int				nums_in_order(int *a, int len_b, int x, int y);

void			pab(int *ab, int *ba);
void			rab(int *ab);
void			rr(int *a, int *b);
void			rrab(int *ab);
void			rrr(int *a, int *b);
void			sab(int *ab);
void			ss(int *a, int *b);

#endif
