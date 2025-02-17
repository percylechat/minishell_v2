#include "minishell.h"

/*
**All functions for redirections (> >> <) shall go there. A work in progress.
*/

void    redir_file(char **res, char *output, int c)
{
    int fd;
    int i;

    i = 0;
    if (c == 0)
        fd = open(res[2], O_CREAT | O_WRONLY | O_TRUNC, 0777);
    else 
        fd = open(res[2], O_APPEND, 0777);
    while (output[i])
        write(fd, &output[i++], 1);
    close(fd);
    return ;
}

void    check_redir(char **res, char *output)
{
    if (ft_strcmp(res[1], ">") == 0)
        redir_file(res, output, 0);
    else if (ft_strcmp(res[1], ">>") == 0)
        redir_file(res, output, 1);
    // else if (ft_strcmp(res[1], "<") == 0)
    //     redir_ext(command, output);
    else
        return;
}