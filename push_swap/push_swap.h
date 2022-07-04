#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

int		number_checker(char **argv, int argc);

void	algo_op(int *a, int *b, int ac);
int		num_max(int x, int *ab);
int		num_min(int x, int *ab);
int		num_max_r(int x, int *ab);
int		num_min_r(int x, int *ab);
int		nums_in_order(int *a, int len_b, int x, int y);
int		*put_int_tab(char **argv, int argc);

void	pab(int *ab, int *ba);
void	rab(int *ab);
void	rr(int *a, int *b);
void	rrab(int *ab);
void	rrr(int *a, int *b);
void	sab(int *ab);
void	ss(int *a, int *b);

#endif
