/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** exec_program.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "lib.h"
#include "minishell.h"

void exec_program(t_minishell *shell, char **env)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
        perror("fork error");
    else if (pid > 0) {
        wait(&shell->status);
    }
    else if (pid == 0) {
        execve(shell->paths[shell->path_access],
            shell->array[shell->array_count], env);
        exit(0);
    }
}