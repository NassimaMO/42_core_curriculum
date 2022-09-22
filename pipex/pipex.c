#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int 	fd[2];
	int		infile;
	int		outfile;
	int		pid;
	char	**tmp;
	char	**paths;
	int		i;

	if (argc < 5)
		return (1);
	i = 0;
	/*if (argv[1] = WRONTOP)
	{
		i = 1;
		infile = open(argv[2], O_RDONLY);
		outfile = open(argv[argc], O_APPEND | O_CREAT | O_RDWR | O_TRUNC);
	}
	else*/
	//{
		i = 0;
		infile = open(argv[1], O_RDONLY);
		outfile = open(argv[argc], O_CREAT | O_RDWR | O_TRUNC);
	//}
	if (pipe(fd) < 0)
		return (2);
	paths = get_paths(envp);
	while (++i < argc)
	{
		pid = fork();
		if (pid == 0)
		{
			if (dup2(infile, STDIN_FILENO) < 0)
				return (free_envp(paths), perror("NAH"), 1);
			if (dup2(fd[1], STDOUT_FILENO) < 0)
				return (free_envp(paths), perror("NO"), 2);
			close(fd[0]);
			close(infile);
			tmp = ft_split(argv[i], ' ');
			access(argv[i], F_OK);
			execve(tmp[0], tmp, paths); // 2e argument = tmp + 1 ?
			free(tmp);
		}
		else if (pid > 0)
		{
			waitpid(-1, NULL, 0);
			if (dup2(outfile, STDOUT_FILENO) < 0)
				return (free_envp(paths), perror("NOPE"), 3);
			if (dup2(fd[0], STDIN_FILENO) < 0)
				return (free_envp(paths), perror("NAY"), 4);
			close(fd[1]);
			close(outfile);
			tmp = ft_split(argv[i], ' ');
			access(argv[i], F_OK);
			execve(tmp[0], tmp, paths);  // 2e argument = tmp + 1 ?
			free(tmp);
		}
		else
			return (free_envp(paths), perror("NOWR"), 4);
	}
	close(fd[0]);
	close(fd[1]);
	free_envp(paths);
}