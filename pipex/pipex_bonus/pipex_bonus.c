/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:09:05 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/04 15:09:07 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_fds(int *fd, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		close(fd[i]);
}

static void	create_files(t_pipex *pipex, char **argv, int argc)
{
	if (!ft_strncmp(argv[1], "here_doc", 8) && ft_strlen(argv[1]) == 8)
	{
		pipex->nbr_cmds--;
		pipex->limiter = argv[2];
		pipex->heredoc = heredoc(pipex);
		pipex->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, \
							0644);
	}
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		pipex->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	if (pipex->outfile < 0)
	{
		if (pipex->heredoc)
		{
			close(pipex->infile);
			unlink("heredoc_file");
		}
		perror("OUTFILE ERROR");
		exit(1);
	}
	if (pipex->infile < 0)
		perror("INFILE ERROR");
}

static void	create_pipes(t_pipex *pipex)
{
	int	i;

	i = -1;
	pipex->fd = malloc(sizeof(int) * 2 * pipex->nbr_cmds);
	if (!pipex->fd)
		exit (-1);
	while (++i < pipex->nbr_cmds)
	{
		if (pipe(pipex->fd + 2 * i) < 0)
		{
			free(pipex->fd);
			perror("PIPE ERROR");
			exit(2);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_pipex	pipex;

	if (argc < 5)
		return (1);
	pipex.nbr_cmds = argc - 3;
	pipex.argv = argv;
	pipex.heredoc = 0;
	create_files(&pipex, argv, argc);
	create_pipes(&pipex);
	pipex.paths = get_paths(envp);
	if (!pipex.paths)
		return (free(pipex.fd), -1);
	i = -1;
	while (++i < pipex.nbr_cmds)
		child_process(&pipex, i);
	close_fds(pipex.fd, pipex.nbr_cmds * 2);
	waitpid(-1, NULL, 0);
	close(pipex.infile);
	close(pipex.outfile);
	if (pipex.heredoc)
		unlink("heredoc_file");
	free(pipex.fd);
	free_envp(pipex.paths);
	return (0);
}
