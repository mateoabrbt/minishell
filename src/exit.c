/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** exit.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "minishell.h"

void exit_minishell(t_minishell *shell, char **env)
{
    (void)env;
    (void)shell;
    if (isatty(0) == 1)
        my_putstr("exit\n");
    free_minishell(shell);
    exit (0);
}