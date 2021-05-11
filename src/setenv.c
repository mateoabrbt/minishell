/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** setenv.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "minishell.h"

char *modify_env(char *dest, char *str, char *str2, char *str3)
{
    int c = 0;

    for (int i = 0; str[i] != '\0'; i++, c++)
        dest[c] = str[i];
    for (int i = 0; str2[i] != '\0'; i++, c++)
        dest[c] = str2[i];
    if (str3 != NULL)
        for (int i = 0; str3[i] != '\0'; i++, c++)
            dest[c] = str3[i];
    dest[c] = '\0';
    return (dest);
}

char *modify_env2(char *dest, char *str, char *str2)
{
    int c = 0;

    for (int i = 0; str[i] != '\0'; i++, c++)
        dest[c] = str[i];
    for (int i = 0; str2[i] != '\0'; i++, c++)
        dest[c] = str2[i];
    dest[c] = '\0';
    return (dest);
}

char **new_setenv(char **env, char **array, int sizeenv)
{
    int o = 0;
    char **newenv = malloc(sizeof(char *) * (sizeenv + 2));

    for (int i = 0; env[i] != NULL; i++) {
        newenv[o] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        newenv[o] = my_strcpy(env[i], newenv[o]);
        o++;
    }
    if (array[2] != NULL) {
        newenv[o] = malloc(sizeof(char) * (my_strlen
                    (array[1]) + my_strlen(array[2]) + 2));
        newenv[o] = modify_env(newenv[o], array[1], "=", array[2]);
    } else {
        newenv[o] = malloc(sizeof(char) * (my_strlen
                    (array[1]) + 2));
        newenv[o] = modify_env2(newenv[o], array[1], "=");
    }
    newenv[o + 1] = NULL;
    return (newenv);
}

char **setenv_minishell(t_minishell *shell, char **env)
{
    int i = 0;
    int sizeenv = my_count_array(env);
    int sizearray = my_count_array(shell->array[shell->array_count]);

    if (sizearray > 3)
        my_puterror("setenv: Too many arguments.\n");
    else if (sizearray == 1) {
        env_minishell(shell, env);
        return (env);
    } else {
        while (i != (sizeenv)) {
            if (my_strncmp(env[i],
                    shell->array[shell->array_count][1], '=', '\0') == 1) {
                if (shell->array[2] != NULL) {
                    env[i] = malloc((my_strlen
                        (shell->array[shell->array_count][1]) +
                        my_strlen(shell->array[shell->array_count][2]) + 2));
                    env[i] = modify_env(env[i], shell->array[shell->array_count]
                        [1], "=", shell->array[shell->array_count][2]);
                } else {
                    env[i] = malloc((my_strlen(shell->array
                        [shell->array_count][1]) + 2));
                    env[i] = modify_env2(env[i], shell->array
                        [shell->array_count][1], "=");
                }
                return env;
            }
            i++;
        }
        env = new_setenv(env, shell->array[shell->array_count], sizeenv);
    }
    return (env);
}