#include "pipex_bonus.h"

void    close_fds(int *fd, int len)
{
	int i;

	i = -1;
	while (++i < len)
		close(fd[i]);
}

int main(int argc, char **argv, char **envp)
{
	int     i;
	t_pipex pipex;

	i = -1;
	if (argc < 5)
		return (1);
	pipex.nbr_cmds = argc - 3;
	pipex.argv = argv;
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.infile < 0 || pipex.outfile < 0)
	{
		close(pipex.outfile);
		unlink(argv[argc - 1]);
		return (perror("OH"), -1);
	}
	pipex.fd = malloc(sizeof(int) * pipex.nbr_cmds);
	while (++i < pipex.nbr_cmds)
	{
		if (pipe(pipex.fd + 2 * i) < 0)
			return (2);
	}
	pipex.paths = get_paths(envp);
	i = -1;
	while (++i < pipex.nbr_cmds)
		child_process(&pipex, i);
	close_fds(pipex.fd, pipex.nbr_cmds * 2);
	waitpid(-1, NULL, 0);
	free_envp(pipex.paths);
	return (0);
}