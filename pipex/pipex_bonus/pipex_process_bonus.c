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
		exit(3);
	}
}

static void	get_the_previous_command(int nbr_cmds)
{
	char	*line;

	if (nbr_cmds == 2)
	{
		line = get_next_line(0);
		while (line)
		{
			ft_printf("%s", line);
			free(line);
			line = get_next_line(0);
		}
	}
	else
		write(2, "permission denied.\n", 19);
}

static void	exec_cmd(t_pipex *pipex, char **tmp)
{
	char	*cmd;
	char	*error_cmd;

	cmd = get_cmd_path(tmp[0], pipex->paths);
	if (!cmd)
	{
		if (tmp[0])
		{
			error_cmd = ft_strjoin("command not found: ", tmp[0]);
			error_cmd = ft_strjoin_free(error_cmd, "\n");
			write(2, error_cmd, ft_strlen(error_cmd));
			free(error_cmd);
		}
		else
			get_the_previous_command(pipex->nbr_cmds);
		free_envp(pipex->paths);
		free(pipex->fd);
		free_envp(tmp);
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
