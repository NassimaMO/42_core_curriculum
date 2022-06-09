/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:13:52 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/27 10:13:54 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

# define BUFFER_SIZE 1

char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);

char	*get_next_line(int fd);

#endif
