/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:50:16 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/04 13:07:55 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line_bonus.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_data_stacks
{
	int		*a;
	int		*b;
	int		len_a;
	int		len_b;
}				t_data_stacks;

int		number_checker(char **argv, int argc);
int		get_num_param(char **argv, int argc);
int		*put_int_tab(char **argv, int argc);
int		verif_instructs(char **instruct, int length);
int		nums_in_order(int *a, int len);
void	free_tab(char **tab_tmp);

int		execute_instruct(char **tab, int len_tab, int *a, int len_a);

void	pab(int *ab, int *ba, int len_ab, int len_ba);
void	rab(int *ab, int len_ba);
void	rr(int *a, int *b, int len_a, int len_b);
void	rrab(int *ab, int len_ab);
void	rrr(int *a, int *b, int len_a, int len_b);
void	sab(int *ab);
void	ss(int *a, int *b);

#endif
