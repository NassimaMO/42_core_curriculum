/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:08:31 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/06 16:11:17 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_pipex *pipex, char **tmp)
{
	char	*cmd;

	cmd = get_cmd_path(tmp[0], pipex->paths);
	if (!cmd)
	{
		free_envp(pipex->paths);
		free_envp(tmp);
		free(cmd);
		perror("COMMAND NOT FOUND.");
		exit(4);
	}
	execve(cmd, tmp, pipex->paths);
	free(tmp);
	free(cmd);
}

void	neg_pid(t_pipex *pipex, int pid)
{
	if (pid < 0)
	{
		free_envp(pipex->paths);
		perror("PROCESS ERROR");
		exit(5);
	}
}

void	first_cmds(t_pipex *pipex)
{
	int		pid1;
	char	**tmp;

	pid1 = fork();
	if (pid1 == 0)
	{
		if (dup2(pipex->infile, STDIN_FILENO) < 0 || \
			dup2(pipex->fd[1], STDOUT_FILENO) < 0)
		{
			free_envp(pipex->paths);
			perror("DUP ERROR");
			exit(3);
		}
		close(pipex->fd[0]);
		close(pipex->infile);
		tmp = ft_split(pipex->argv[2], ' ');
		if (!tmp)
		{
			free_envp(pipex->paths);
			exit(-1);
		}
		exec_cmd(pipex, tmp);
	}
	neg_pid(pipex, pid1);
}

void	second_cmds(t_pipex *pipex)
{
	int		pid2;
	char	**tmp;

	pid2 = fork();
	if (pid2 == 0)
	{
		if (dup2(pipex->outfile, STDOUT_FILENO) < 0 || \
			dup2(pipex->fd[0], STDIN_FILENO) < 0)
		{
			free_envp(pipex->paths);
			perror("DUP ERROR");
			exit(7);
		}
		close(pipex->fd[1]);
		close(pipex->outfile);
		tmp = ft_split(pipex->argv[3], ' ');
		if (!tmp)
		{
			free_envp(pipex->paths);
			exit(-1);
		}
		exec_cmd(pipex, tmp);
	}
	neg_pid(pipex, pid2);
}
