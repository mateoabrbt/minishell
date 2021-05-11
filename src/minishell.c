/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** minishell.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "minishell.h"

void free_minishell(t_minishell *shell)
{
    for (int i = 0; shell->paths[i] != NULL; i++)
            free(shell->paths[i]);
        free(shell->paths);
}

char *get_info_minishell(t_minishell *shell, char **env)
{
    size_t sizeread = 0;
    char *bufferarg = NULL;

    minishell_init(shell);
    fill_struct(shell, env);
    if (isatty(shell->status) == 1)
        display_minishell();
    if (getline(&bufferarg, &sizeread, stdin) == -1) {
        my_putstr("exit\n");
        exit(0);
    }
    return bufferarg;
}

int minishell(char **env)
{
    t_minishell shell;
    int tmp_count = 0;
    char ***tmp = NULL;
    char *bufferarg = NULL;

    bufferarg = get_info_minishell(&shell, env);
    shell.arg = my_clean_str(bufferarg);
    tmp = create_triple_array(shell.arg, ';');
    while (tmp[tmp_count] != NULL) {
        minishell_init(&shell);
        fill_struct(&shell, env);
        shell.array = tmp;
        shell.array_count = tmp_count;
        env = handle_arg(&shell, env);
        if (env == NULL)
            return (-1);
        tmp_count++;
        free_minishell(&shell);
    }
    minishell(env);
    return (0);
}
