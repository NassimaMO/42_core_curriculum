/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:09:30 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/04 15:09:31 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	check_file(int fd)
{
	if (fd < 0)
	{
		close(fd);
		unlink("heredoc_file");
		perror("FILE ERROR");
		exit(1);
	}
}

int	heredoc(t_pipex *pipex)
{
	int		tmp_fd;
	char	*line;

	tmp_fd = open("heredoc_file", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	check_file(tmp_fd);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
		{
			close(tmp_fd);
			unlink("here_doc");
			exit(-1);
		}
		if (!ft_strncmp(line, pipex->limiter, ft_strlen(pipex->limiter)) && \
			ft_strlen(line) - 1 == ft_strlen(pipex->limiter))
			break ;
		write(tmp_fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(tmp_fd);
	pipex->infile = open("heredoc_file", O_RDONLY);
	return (check_file(pipex->infile), 1);
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
