/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** env.c
*/

#include <stdio.h>
#include <unistd.h>
#include "lib.h"
#include "minishell.h"

void env_minishell(t_minishell *shell, char **env)
{
    (void)shell;
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putstr("\n");
    }
}