# ifndef PIPEX_H
# define PIPEX_H

#include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// typedef struct		s_cmd
// {
// 	char				*cmd;
// 	char				**args;
// }                       t_cmd;

typedef struct  s_data
{
    char    **paths;
    char    **env;
    char    **cmds;
    int     cmd_size;
    int     fd[2];
    int     path_size;
    int     prev;
    __pid_t *pids;
    char    *in_file;
    char    *out_file;
    int     here_doc;
}               t_data;


//parsing fonctions
char **find_paths_and_store(char **env);
void    store_cmds(t_data *data, int argc, char *argv[]);

//open fonctions
void    open_failed(t_data *data, int first);
void my_open(int nb, t_data *data);
void    open_worked(int nb, t_data *data, int opn);

//execve fonctions
void    my_exec(t_data *data, char *curr_cmd);

#endif