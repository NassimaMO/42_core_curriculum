#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int 	fd[2];
	int		infile;
	int		outfile;
	int		pid1;
	int     pid2;
	char    *cmd;
	char	**tmp;
	char	**paths;

	if (argc < 5)
		return (1);
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
	{
		close(outfile);
		unlink(argv[argc - 1]);
		return (perror("OH"), -1);
	}
	if (pipe(fd) < 0)
		return (2);
	paths = get_paths(envp);
	pid1 = fork();
	if (pid1 == 0)
	{
		if (dup2(infile, STDIN_FILENO) < 0)
			return (free_envp(paths), perror("NAH"), 3);
		if (dup2(fd[1], STDOUT_FILENO) < 0)
			return (free_envp(paths), perror("NO"), 4);
		close(fd[0]);
		close(infile);
		tmp = ft_split(argv[2], ' ');
		cmd = get_cmd_path(tmp[0], paths);
		printf("%s\n", cmd);
		if (!cmd)
			return (free_envp(paths), free_envp(tmp), free(cmd), \
			perror("AYWHATSTHATCOMMANDMATE"), 5);
		execve(cmd, tmp, paths);
		free(tmp);
		free(cmd);
	}
	else if (pid1 < 0)
		return (free_envp(paths), perror("NOWR"), 6);
	pid2 = fork();
	if (pid2 == 0)
	{
		if (dup2(outfile, STDOUT_FILENO) < 0)
			return (free_envp(paths), perror("NOPE"), 7);
		if (dup2(fd[0], STDIN_FILENO) < 0)
			return (free_envp(paths), perror("NAY"), 8);
		close(fd[1]);
		close(outfile);
		tmp = ft_split(argv[3], ' ');
		cmd = get_cmd_path(tmp[0], paths);
		if (!cmd)
			return (free_envp(paths), free_envp(tmp), free(cmd), \
			perror("AYWHATSTHATSECONDCOMMANDMATE"), 9);
		execve(cmd, tmp, paths);
		free(tmp);
	}
	else if (pid1 < 0)
		return (free_envp(paths), perror("NOWR"), 10);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free_envp(paths);
	return (0);
}