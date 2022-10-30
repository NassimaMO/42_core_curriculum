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

static int	check_cmds(t_pipex *pipex)
{
	int		i;
	int		nbr_error;
	char	**tmp;
	char	*error_cmd;
	char	*cmd;

	i = -1;
	nbr_error = 0;
	while (++i < 2)
	{
		tmp = ft_split(pipex->argv[i + 2], ' ');
		if (!tmp)
		{
			free_envp(pipex->paths);
			exit(-1);
		}
		cmd = get_cmd_path(tmp[0], pipex->paths);
		if (!cmd)
		{
			if (tmp[0])
				error_cmd = ft_strjoin(tmp[0], " :command not found");
			else
				error_cmd = ft_strjoin("''", " :command not found");
			error_cmd = ft_strjoin_free(error_cmd, "\n");
			write(2, error_cmd, ft_strlen(error_cmd));
			free(error_cmd);
			nbr_error++;
		}
		if (cmd && ft_strncmp(cmd, tmp[0], sizeof(cmd)))
			free(cmd);
		free_envp(tmp);
	}
	return (nbr_error);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (1);
	pipex.argv = argv;
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.infile < 0)
		perror(argv[1]);
	if (pipex.outfile < 0)
		return (perror(argv[argc - 1]), 1);
	if (pipe(pipex.fd) < 0)
		return (perror("pipe error"), 2);
	pipex.paths = get_paths(envp);
	if (check_cmds(&pipex))
		return (free_envp(pipex.paths), 1);
	first_cmds(&pipex);
	second_cmds(&pipex);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	waitpid(-1, NULL, 0);
	free_envp(pipex.paths);
	return (0);
}
