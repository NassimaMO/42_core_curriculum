/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:50:22 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/04 17:50:23 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

# define WRONTOP "here_doc"

typedef struct s_pipex
{
	char	**argv;
	int		fd[2];
	char	**paths;
	int		infile;
	int		outfile;
}			t_pipex;

char	**get_paths(char **envp);
void	free_envp(char **envp);
char	*get_cmd_path(char *cmd, char **paths);
void	child_process(t_pipex *pipex, int i);
void	close_fds(int *fd, int len);
void	first_cmds(t_pipex *pipex);
void	second_cmds(t_pipex *pipex);

#endif
