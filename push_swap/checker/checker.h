#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line_bonus.h"

# define INT_MAX 2147483647

int				number_checker(char **argv, int argc);
int				verif_double(char *a, char **argv, int x);
long long int	nbr_to_str(char *a);
int				*put_int_tab(char **argv, int argc);

int             nums_in_order(int *a, int *b);
int             execute_instruct(char **tab, int *a, int *b);

void			pab(int *ab, int *ba);
void			rab(int *ab);
void			rr(int *a, int *b);
void			rrab(int *ab);
void			rrr(int *a, int *b);
void			sab(int *ab);
void			ss(int *a, int *b);

#endif
