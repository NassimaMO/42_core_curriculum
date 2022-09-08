/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:42:03 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/30 14:42:06 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"

int		ft_printf_putstr_fd(char *s, int fd, int *count);
void	ft_printf_putnbr_fd(long long int n, int fd, int *i);

int		ft_printf_putnbr_base(long int nbr, char *base, int n, int *i);
int		ft_printf(const char *str, ...);

#endif
