/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** modify_pwd_oldpwd.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "minishell.h"

char **add_pwd_oldpwd(char **env, char *type, char *wd, int sizeenv)
{
    int o = 0;
    char **newenv = malloc(sizeof(char *) * (sizeenv + 2));

    for (int i = 0; env[i] != NULL; i++) {
        newenv[o] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        newenv[o] = my_strcpy(env[i], newenv[o]);
        o++;
    }
    newenv[o] = malloc(sizeof(char) * (my_strlen
                (type) + my_strlen(wd) + 2));
    newenv[o] = modify_env(newenv[o], type, "=", wd);
    newenv[o + 1] = NULL;
    return (newenv);
}

char **check_pwd_oldpwd(int *status, char *oldpwd, char *pwd, char **env)
{
    int sizeenv = my_count_array(env);

    if (status[0] != 1)
        env = add_pwd_oldpwd(env, "PWD", pwd, sizeenv);
    if (status[1] != 1)
        env = add_pwd_oldpwd(env, "OLDPWD", oldpwd, sizeenv);
    return (env);
}

char **change_pwd_oldpwd(char *oldpwd, char *pwd, char **env)
{
    int i;
    int *status = NULL;
    int sizeenv = my_count_array(env);

    status = malloc (sizeof(int) * 2);
    for (i = 0; i != (sizeenv); i++) {
        if (my_strncmp(env[i], "PWD", '=', '\0') == 1) {
            env[i] = malloc(sizeof(char) * (my_strlen("PWD")
                        + my_strlen(pwd) + 2));
            env[i] = modify_env(env[i], "PWD", "=", pwd);
            status[0] = 1;
        } else if (my_strncmp(env[i], "OLDPWD", '=', '\0') == 1) {
            env[i] = malloc(sizeof(char) * (my_strlen("OLDPWD")
                        + my_strlen(oldpwd) + 2));
            env[i] = modify_env(env[i], "OLDPWD", "=", oldpwd);
            status[1] = 1;
        }
    }
    env = check_pwd_oldpwd(status, oldpwd, pwd, env);
    return (env);
}