/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** fill_struct.c
*/

#include <unistd.h>
#include "lib.h"
#include "minishell.h"

int find_path(char **env)
{
    int i = 0;

    for (; env[i] != NULL; i++) {
        if (my_strncmp("PATH=", env[i], '=', '=') == 1)
            break;
        if (my_strncmp("PATH=", env[i], '=', '=') == 0 
                && env[i + 1] == NULL) {
            return (-1);
        }
    }
    return (i);
}

int find_home(t_minishell *shell, char **env)
{
    int i = 0;

    if (env[i] == NULL)
        shell->home_status = -1;
    else {
        for (; env[i] != NULL; i++) {
            if (my_strncmp("HOME=", env[i], '=', '=') == 1)
                break;
            if (my_strncmp("HOME=", env[i], '=', '=') == 0 
                    && env[i + 1] == NULL) {
                shell->home_status = -1;
                return (0);
            }
        }
    }
    return (i);
}

void fill_struct(t_minishell *shell, char **env)
{
    int pos_path = 0;
    int pos_home = 0;
    char *env_path = NULL;

    pos_path = find_path(env);
    pos_home = find_home(shell, env);
    env_path = &env[pos_path][5];
    if (pos_path > 0)
        shell->paths = create_array(env_path, ':');
    if (pos_home > 0)
        shell->home = &env[pos_home][5];
}
