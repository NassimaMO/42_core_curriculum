#include "pipex.h"

void    first_cmds(t_pipex *pipex)
{
	int		pid1;
	char    *cmd;
	char	**tmp;
    
    pid1 = fork();
	if (pid1 == 0)
	{
		if (dup2(pipex->infile, STDIN_FILENO) < 0)
		{
			free_envp(pipex->paths);
			perror("NAH");
			exit(3);
		}
		if (dup2(pipex->fd[1], STDOUT_FILENO) < 0)
		{
			free_envp(pipex->paths);
			perror("NO");
			exit(4);
		}
		close(pipex->fd[0]);
		close(pipex->infile);
		tmp = ft_split(pipex->argv[2], ' ');
		if (!tmp)
		{
			free_envp(pipex->paths);
			exit(-1);
		}
		cmd = get_cmd_path(tmp[0], pipex->paths);
		if (!cmd)
		{
			free_envp(pipex->paths);
			free_envp(tmp);
			free(cmd);
			perror("AYWHATSTHATCOMMANDMATE");
			exit(5);
		}
		execve(cmd, tmp, pipex->paths);
		free(tmp);
		free(cmd);
	}
	else if (pid1 < 0)
	{
		free_envp(pipex->paths);
		perror("NOWR");
		exit(6);
	}
}

void    second_cmds(t_pipex *pipex)
{
	int		pid2;
	char    *cmd;
	char	**tmp;

    pid2 = fork();
	if (pid2 == 0)
	{
		if (dup2(pipex->outfile, STDOUT_FILENO) < 0)
		{
			free_envp(pipex->paths);
			perror("NOPE");
			exit(7);
		}
		if (dup2(pipex->fd[0], STDIN_FILENO) < 0)
		{
			free_envp(pipex->paths);
			perror("NAY");
			exit(8);
		}
		close(pipex->fd[1]);
		close(pipex->outfile);
		tmp = ft_split(pipex->argv[3], ' ');
		if (!tmp)
		{
			free_envp(pipex->paths);
			exit(-1);
		}
		cmd = get_cmd_path(tmp[0], pipex->paths);
		if (!cmd)
		{
			free_envp(pipex->paths);
			free_envp(tmp);
			free(cmd);
			perror("AYWHATSTHATCOMMANDMATE");
			exit(9);
		}
		execve(cmd, tmp, pipex->paths);
		free(tmp);
		free(cmd);
	}
	else if (pid2 < 0)
	{
		free_envp(pipex->paths);
		perror("NOWR");
		exit(10);
	}
}