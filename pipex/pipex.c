/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:08:47 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/04 15:08:48 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (1);
	pipex.argv = argv;
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.outfile < 0)
		return (perror("OUTFILE ERROR"), 1);
	if (pipex.infile < 0)
		perror("INFILE ERROR");
	if (pipe(pipex.fd) < 0)
		return (perror("PIPE ERROR"), 2);
	pipex.paths = get_paths(envp);
	first_cmds(&pipex);
	second_cmds(&pipex);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	waitpid(-1, NULL, 0);
	free_envp(pipex.paths);
	return (0);
}
