#include "pipex_bonus.h"

void    heredoc(t_pipex *pipex)
{
	int tmp_fd;
	char *line;

	tmp_fd = open("heredoc_file", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!ft_strncmp(line, pipex->limiter, ft_strlen(pipex->limiter))) // to change bcs if its longer I will still go with it
			break;
		write(tmp_fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(tmp_fd);
	pipex->infile = open("heredoc_file", O_RDONLY);
}

/*int	main(int argc, char **argv)
{
	t_pipex pipex;
	char *line;

	pipex.limiter = argv[1];
	printf("%s\n", pipex.limiter);
	heredoc(&pipex);
	printf("%d\n", pipex.infile);
	line = get_next_line(pipex.infile);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(pipex.infile);
	}
	close(pipex.infile);
}*/