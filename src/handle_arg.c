/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** handle_array.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "minishell.h"

static const t_handle_args_void ARGS_VOID[] = {
    (t_handle_args_void) {"env", env_minishell},
    (t_handle_args_void) {"exit", exit_minishell},
};

static const t_handle_args_char ARGS_CHAR[] = {
    (t_handle_args_char) {"cd", cd_minishell},
    (t_handle_args_char) {"setenv", setenv_minishell},
    (t_handle_args_char) {"unsetenv", unsetenv_minishell},
};

char **handle_arg(t_minishell *shell, char **env)
{
    for (long unsigned int i = 0; i < sizeof(ARGS_VOID)
            / sizeof(t_handle_args_void); i += 1)
        if (my_strncmp(ARGS_VOID[i].arg,
            shell->array[shell->array_count][0], '\0', '\0') == 1) {
            ARGS_VOID[i].function(shell, env);
            return (env);
        }
    for (long unsigned int i = 0; i < sizeof(ARGS_CHAR)
            / sizeof(t_handle_args_char); i += 1)
        if (my_strncmp(ARGS_CHAR[i].arg,
            shell->array[shell->array_count][0], '\0', '\0') == 1) {
            env = ARGS_CHAR[i].function(shell, env);
            return (env);
        }
    if (test_path(shell) == -1)
        return (NULL);
    exec_program(shell, env);
    return (env);
}