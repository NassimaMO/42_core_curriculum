/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:50:39 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/31 11:09:45 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define WRONTOP "here_doc"

typedef struct s_pipex
{
	char	**argv;
	int		nbr_cmds;
	int		*fd;
	char	**paths;
	int		infile;
	int		outfile;
	int		heredoc;
	char	*limiter;
}			t_pipex;

char	**get_paths(char **envp);
void	free_envp(char **envp);
char	*check_cmd(t_pipex *pipex, char **tmp);
char	*get_cmd_path(char *cmd, char **paths);
void	child_process(t_pipex *pipex, int i);
void	close_fds(int *fd, int len, int in, int out);
int		heredoc(t_pipex *pipex);
#endif
