#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int 	fd[2];
	int		infile;
	int		outfile;
	int		pid;
	char	**tmp;
	int		i;

	if (argc < 5)
		return (1);
	i = 0;
	if (argv[1] = WRONTOP)
	{
		i = 1;
		infile = open(argv[2], O_RDONLY);
		outfile = open(argv[argc], O_APPEND | O_CREAT | O_RDWR | O_TRUNC);
	}
	else
	{
		i = 0;
		infile = open(argv[1], O_RDONLY);
		outfile = open(argv[argc], O_CREAT | O_RDWR | O_TRUNC);
	}
	if (pipe(fd) < 0)
		return (2);
	while (++i < argc)
	{
		pid = fork();
		if (pid == 0)
		{
			if (dup2(infile, STDIN_FILENO) < 0)
				return (perror("DUDE SERIOUSLY WTF"));
			if (dup2(fd[1], STDOUT_FILENO) < 0)
				return (perror("OK U KNOW WHAT ? WHATEVER"));
			close(fd[0]);
			close(infile);
			tmp = ft_split(argv[i], ' ');
			access(tmp[0], F_OK);
			execve(..., tmp, smt(envp));
			free(tmp);
		}
		else if (pid > 0)
		{
			waitpid(-1, NULL, 0);
			if (dup2(outfile, STDOUT_FILENO) < 0)
				return (perror("AINT NO WAY ITS HAPPENING AT THIS MOMENT RIGHT NOW"));
			if (dup2(fd[0], STDIN_FILENO) < 0)
				return (perror("HUUUUUUUUUUUHHHHHH !?!??"));
			close(fd[1]);
			close(outfile);
			tmp = ft_split(argv[i], ' ');
			access(tmp[0], F_OK);
			execve(..., tmp, smt(envp));
			free(tmp);
		}
		else
			return (perror("THERES A PROBLEM RIGHT HERE DUDE"));
	}
	close(fd[0]);
	close(fd[1]);
}