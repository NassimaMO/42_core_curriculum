/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:50:41 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/07 14:50:55 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

void	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(long long int n, int *i, int p, int m);
int		ft_putstr_fd(char *s, int fd, int *count);
int	ft_strlen(const char *s);

#endif
