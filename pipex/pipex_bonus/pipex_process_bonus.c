/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:09:36 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/04 15:09:38 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	dup_fds(int in, int out, t_pipex *pipex)
{
	if (dup2(in, STDIN_FILENO) < 0 || dup2(out, STDOUT_FILENO) < 0)
	{
		free(pipex->fd);
		free_envp(pipex->paths);
		perror("DUP ERROR");
		exit(3);
	}
}

static void	exec_cmd(t_pipex *pipex, char **tmp)
{
	char	*cmd;

	cmd = get_cmd_path(tmp[0], pipex->paths);
	if (!cmd)
	{
		free(pipex->fd);
		free_envp(pipex->paths);
		free_envp(tmp);
		free(cmd);
		ft_printf("COMMAND ERROR.");
		exit(4);
	}
	execve(cmd, tmp, pipex->paths);
	free(tmp);
	free(cmd);
}

static void	neg_pid(t_pipex *pipex, int pid)
{
	if (pid < 0)
	{
		free(pipex->fd);
		free_envp(pipex->paths);
		perror("PROCESS ERROR");
		exit(5);
	}
}

void	child_process(t_pipex *pipex, int i)
{
	int		pid;
	char	**tmp;

	pid = fork();
	if (pid == 0)
	{
		if (i == 0)
			dup_fds(pipex->infile, pipex->fd[2 * i + 1], pipex);
		else if (i == pipex->nbr_cmds - 1)
			dup_fds(pipex->fd[(i - 1) * 2], pipex->outfile, pipex);
		else
			dup_fds(pipex->fd[(i - 1) * 2], pipex->fd[2 * i + 1], pipex);
		close_fds(pipex->fd, pipex->nbr_cmds * 2);
		tmp = ft_split(pipex->argv[i + 2 + pipex->heredoc], ' ');
		if (!tmp)
		{
			free(pipex->fd);
			free_envp(pipex->paths);
			exit(-1);
		}
		exec_cmd(pipex, tmp);
	}
	neg_pid(pipex, pid);
}
