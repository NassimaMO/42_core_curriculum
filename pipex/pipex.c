#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;

	if (argc != 5)
		return (1);
	pipex.argv = argv;
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.infile < 0 || pipex.outfile < 0)
	{
		close(pipex.outfile);
		unlink(argv[argc - 1]);
		return (perror("OH"), -1);
	}
	if (pipe(pipex.fd) < 0)
		return (2);
	pipex.paths = get_paths(envp);
	first_cmds(&pipex);
	second_cmds(&pipex);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	waitpid(-1, NULL, 0);
	free_envp(pipex.paths);
	return (0);
}