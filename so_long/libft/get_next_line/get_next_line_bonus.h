/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:13:52 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/06 15:27:53 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft.h"

# define BUFFER_SIZE 1

char	*ft_strjoin_free(char *s1, char const *s2);

char	*get_next_line(int fd);

#endif
