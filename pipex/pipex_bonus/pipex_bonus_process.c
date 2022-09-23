#include "pipex_bonus.h"

void    dup_fds(int in, int out, char **paths)
{
	if (dup2(in, STDIN_FILENO) < 0 || dup2(out, STDOUT_FILENO) < 0)
	{
		free_envp(paths);
		perror("NOPE OR NAY");
		exit(-1);
	}
}

void    child_process(t_pipex *pipex, int i)
{
	int pid;
	char **tmp;
	char *cmd;

	pid = fork();
	if (pid == 0)
	{
		if (i == 0)
			dup_fds(pipex->infile, pipex->fd[2 * i + 1], pipex->paths);
		else if (i == pipex->nbr_cmds - 1)
			dup_fds(pipex->fd[(i - 1) * 2], pipex->outfile, pipex->paths);
		else
			dup_fds(pipex->fd[(i - 1) * 2], pipex->fd[2 * i + 1], pipex->paths);
		close_fds(pipex->fd, pipex->nbr_cmds * 2);
		tmp = ft_split(pipex->argv[i + 2], ' ');
		cmd = get_cmd_path(tmp[0], pipex->paths);
		if (!cmd)
		{
			free_envp(pipex->paths);
			free_envp(tmp);
			free(cmd);
			perror("AYWHATSTHATCOMMANDMATE");
			exit(-2);
		}
		execve(cmd, tmp, pipex->paths);
		free(tmp);
		free(cmd);
	}
	else if (pid < 0)
	{
		free_envp(pipex->paths);
		perror("NOWR");
		exit(-3);
	}
}