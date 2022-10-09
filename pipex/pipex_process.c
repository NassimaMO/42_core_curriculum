/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:08:31 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/09 15:32:32 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_the_previous_command(void)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(0);
	}
}

void	exec_cmd(t_pipex *pipex, char **tmp)
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
			get_the_previous_command();
		free_envp(pipex->paths);
		free_envp(tmp);
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
