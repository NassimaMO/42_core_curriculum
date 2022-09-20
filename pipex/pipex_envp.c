#include "pipex.h"

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

	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
			break ;
	}
	//printf("%s\n\n", envp[i]);
	tmp = ft_split(envp[i] + 5, ':');
	i = -1;
	while (tmp && tmp[++i])
	{
		if (tmp[i][ft_strlen(tmp[i]) - 1] != '/')
			tmp[i] = ft_strjoin_free(tmp[i], "/");
	}
	/*i = -1;
	while (tmp && tmp[++i])
		printf("%s\n\n", tmp[i]);*/
	return (tmp);
}