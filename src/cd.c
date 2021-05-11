/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** cd.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "minishell.h"

char *find_oldpwd(char **env)
{
    int i;
    char *oldpwd = NULL;

    if (env == NULL)
        return NULL;
    else {
        for (i = 0; env[i] != NULL; i++) {
            if (my_strncmp("OLDPWD=", env[i], '=', '=') == 1)
                break;
            if (my_strncmp("OLDPWD=", env[i], '=', '=') == 0 
                    && env[i + 1] == NULL)
                return NULL;
        }
        oldpwd = &env[i][7];
    }
    return oldpwd;
}

int cd_old(char **env)
{
    char *path = NULL;

    if (path == NULL) {
        my_puterror(": No such file or directory.\n");
        return -1;
    }
    if (chdir(path) == -1) {
        path = find_oldpwd(env);
        my_puterror(path);
        my_puterror(" : No such file or directory.\n");
        return -1;
    }
    return 0;
}

int cd_home(t_minishell *shell)
{
    if (shell->home == NULL)
        my_puterror("cd: No home directory.\n");
    if (chdir(shell->home) == -1 && shell->home != NULL) {
        my_puterror(": No such file or directory.\n");
        return -1;
    }
    return 0;
}

int cd_arg(t_minishell *shell)
{
    if (chdir(shell->array[shell->array_count][1]) == -1) {
        if (access(shell->array[shell->array_count][1], X_OK) == 0) {
            my_puterror(shell->array[shell->array_count][1]);
            my_puterror(": Not a directory.\n");
            return -1;
        }
        my_puterror(shell->array[shell->array_count][1]);
        my_puterror(": No such file or directory.\n");
        return -1;
    }
    return 0;
}

char **cd_minishell(t_minishell *shell, char **env)
{
    int status = 0;
    size_t old_size = 0;
    size_t new_size = 0;
    char *old_buffer = NULL;
    char *new_buffer = NULL;
    int sizearray = my_count_array(shell->array[shell->array_count]);

    if (sizearray > 2) {
        my_puterror("cd: Too many arguments.\n");
        status = -1;
    } else if (sizearray == 1) {
        old_buffer = getcwd(old_buffer, old_size);
        status = cd_home(shell);
        new_buffer = getcwd(new_buffer, new_size);
    } else {
        old_buffer = getcwd(old_buffer, old_size);
        if (my_strncmp(shell->array[shell->array_count][1],
                "-", '\0', '\0') == 1)
            status = cd_old(env);
        else
            status = cd_arg(shell);
        new_buffer = getcwd(new_buffer, new_size);
    }
    if (status != -1)
        env = change_pwd_oldpwd(old_buffer, new_buffer, env);
    return (env);
}