#include "pipex.h"

void    close_fds(int *fd, int len, int x, int y)
{
    int i;

    i = -1;
    while (++i < len)
    {
        if (i != x && i != y)
            close(fd[i]);
    }
}

int main(int argc, char **argv, char **envp)
{
    int     i;
    t_pipex pipex;

    i = -1;
	if (argc < 5)
		return (1);
    pipex.argc = argc;
    pipex.argv = argv;
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC);
	if (pipex.infile < 0 || pipex.outfile < 0)
		return (perror("OH"), -1);
    pipex.fd = malloc(sizeof(int) * argc - 3);
    while (++i < argc - 3)
    {
        if (pipe(pipex.fd + 2 * i) < 0)
		    return (2);
    }
    pipex.paths = get_paths(envp);
    i = -1;
    while (++i < argc - 3)
    {
        printf("%d\n", i);
        child_process(&pipex, i);
    }
////////////////////////////////////////////
/*


    int pid = fork();
    if (pid == 0)
    {
        if (dup2(pipex.fd[0], STDIN_FILENO) < 0 || dup2(pipex.outfile, STDOUT_FILENO) < 0)
        {
            free_envp(pipex.paths);
            perror("NOPE OR NAY");
            exit(-1);
        }
        close_fds(pipex.fd, pipex.argc - 3, 0, -1);
        close(pipex.infile);
        char **tmp = ft_split(pipex.argv[i + 2], ' ');
        char *cmd = get_cmd_path(tmp[0], pipex.paths);
        if (!cmd)
        {
            free_envp(pipex.paths);
            free_envp(tmp);
            free(cmd);
            perror("AYWHATSTHATCOMMANDMATE");
            exit(-2);
        }
        execve(cmd, tmp, pipex.paths);
        free(tmp);
        free(cmd);
    }
	else if (pid < 0)
	{
		free_envp(pipex.paths);
		perror("NOWR");
		exit(-3);
	}



*///////////////////////////////////////////////////

	close_fds(pipex.fd, argc - 3, -1, -1);
	waitpid(-1, NULL, 0);
	free_envp(pipex.paths);
	return (0);
}