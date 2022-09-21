#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define WRONTOP "here_doc"

typedef struct s_pipex
{
    char    **argv;
    int     argc;
    int     *fd;
    char    **paths;
    int     infile;
    int     outfile;
}              t_pipex;

char    **get_paths(char **envp);
void    free_envp(char **envp);
char    *get_cmd_path(char *cmd, char **paths);
void    child_process(t_pipex *pipex, int i);
void    close_fds(int *fd, int len, int x, int y);
#endif