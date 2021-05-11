/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** unsetenv.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"
#include "minishell.h"

char **new_unsetenv(char **env, int sizeenv, int unset)
{
    int i = 0;
    int o = 0;
    char **newenv = malloc(sizeof(char *) * (sizeenv));

    while (env[i] != NULL) {
        if (i == unset) {
            i++;
        } else {
            newenv[o] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
            newenv[o] = my_strcpy(env[i], newenv[o]);
            o++;
            i++;
        }
    }
    newenv[o + 1] = NULL;
    return (newenv);
}

char **unsetenv_minishell(t_minishell *shell, char **env)
{
    int i = 0;
    int o = 0;
    int sizeenv = my_count_array(env);
    int sizearray = my_count_array(shell->array[shell->array_count]);

    if (sizearray == 1)
        my_puterror("unsetenv: Too few arguments.\n");
    else {
        for (; o != sizearray; o++) {
            i = 0;
            for (; i != (sizeenv); i++)
                if (my_strncmp(env[i], shell->array
                        [shell->array_count][o], '=', '\0') == 1) {
                    env = new_unsetenv(env, sizeenv, i);
                    return env;
                }
        }
    }
    return (env);
}