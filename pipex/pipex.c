#include "pipex.h"

int main(int argc, char **argv)
{
	int fd[2];
	int	*pid;
	int	len;
	int	i;

	if (argc < 5)
		return (1);
	if (argv[1] = WRONTOP)
	{
		len = argc - 3;
		fd[0] = open(argv[2], O_APPEND | O_WRONLY);
		fd[1] = open(argv[argc], O_APPEND | O_WRONLY);
	}
	else
	{
		len = argc - 2;
		fd[0] = open(argv[1], O_WRONLY);
		fd[1] = open(argv[argc], O_WRONLY);
	}
	pid = calloc(len, sizeof(int));
	if (pipe(fd) < 0)
		return (2);
	i = -1;
	while (++i < len)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			dup2(fd[0], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			execve();
		}
	}
	close(fd[0]);
	close(fd[1]);
	i = -1;
	while (++i < len)
	{
		waitpid(pid[i], NULL, 0);
	}
}