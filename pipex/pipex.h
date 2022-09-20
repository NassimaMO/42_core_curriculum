#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define WRONTOP "here_doc"

char    **get_paths(char **envp);
void    free_envp(char **envp);

#endif