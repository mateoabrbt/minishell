/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** clean_env.c
*/

#include <stdlib.h>
#include "lib.h"

char **new_env(char **env, int sizeenv, int unset)
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

char **clean_env(char **env)
{
    int i;
    int sizeenv = my_count_array(env);

    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp("OLDPWD=", env[i], '=', '=') == 1) {
            env = new_env(env, sizeenv, i);
            break;
        }
        if (my_strncmp("OLDPWD=", env[i], '=', '=') == 0 
            && env[i + 1] == NULL)
        return env;
    }
    return env;
}