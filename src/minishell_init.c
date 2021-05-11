/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** minishell_init.c
*/

#include <unistd.h>
#include "minishell.h"

void minishell_init(t_minishell *shell)
{
    shell->status = 1;
    shell->array_count = 0;
    shell->path_access = 0;
    shell->path_status = 0;
    shell->home_status = 0;
    shell->arg = NULL;
    shell->home = NULL;
    shell->array = NULL;
    shell->paths = NULL;
}