/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:06:18 by nmouslim          #+#    #+#             */
/*   Updated: 2022/11/07 14:06:31 by nmouslim         ###   ########.fr       */
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

void	change_pos(t_list **lst);
int		number_checker(char **argv, int argc);
int		verif_double(char *a, char **argv, int argc, int x);
int		*put_int_tab(char **argv, int argc);
void	ft_sort_int_tab(int *tab, int size);

void	rev_scase(int len_a);
int		nums_in_order_rev(int *ab, int len);

void	pab(t_list **list_one, t_list **list_two, int b_lst_init);
void	rab(t_list **lst);
void	rr(t_list **list_one, t_list **list_two);
void	rrab(t_list **lst);
void	rrr(t_list **list_one, t_list **list_two);
void	sab(t_list **lst);
void	ss(t_list **list_one, t_list **list_two);

void	algo_three(t_list **list_a);

void	tri_positionel(t_list **list_a, t_list **list_b, int len, int mediane);

void	get_target_pos(t_list **list_a, t_list **list_b);

int		calculate_cost(int pos, int len);
void	calculate_movements_costs(t_list **list_a, t_list **list_b);
int		get_total_cost(t_list *lst);

void	perform_movement(t_list **list_a, t_list **list_b);

#endif
