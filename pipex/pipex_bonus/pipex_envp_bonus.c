/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_envp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:09:17 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/04 15:09:19 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*cmd_path;

	i = -1;
	while (paths[++i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}

void	free_envp(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		free(envp[i]);
	free(envp);
}

char	**get_paths(char **envp)
{
	int		i;
	char	**tmp;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=/mnt", ft_strlen(envp[i])))
		i++;
	tmp = ft_split(envp[i] + 5, ':');
	if (!tmp)
		return (NULL);
	i = -1;
	while (tmp && tmp[++i])
	{
		if (tmp[i][ft_strlen(tmp[i]) - 1] != '/')
		{
			tmp[i] = ft_strjoin_free(tmp[i], "/");
			if (!tmp[i])
			{
				free_envp(tmp);
				return (NULL);
			}
		}
	}
	return (tmp);
}
