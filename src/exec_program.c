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

void handle_segfault(int status)
{
    if (status == 0)
        return;
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV) {
            my_putstr("Segmentation fault");
            if (__WCOREDUMP(status))
                my_putstr(" (core dumped)");
            my_putstr("\n");
            if (isatty(STDIN_FILENO) != 1)
                exit(139);
        }
        if (WTERMSIG(status) == SIGABRT) {
            my_putstr("Aborted\n");
            if (isatty(STDIN_FILENO) != 1)
                exit(139);
        }
        if (status == 136) {
            my_putstr("Floating exception (core dumped)\n");
            if (isatty(STDIN_FILENO) != 1)
                exit(136);
        }
    }
}

void exec_program(t_minishell *shell, char **env)
{
    pid_t pid;
    int status = 0;

    pid = fork();
    if (pid == -1)
        perror("fork error");
    else if (pid > 0) {
        wait(&status);
        handle_segfault(status);
    }
    else if (pid == 0) {
        if (shell->paths != NULL && shell->path_access != -1) {
            execve(shell->paths[shell->path_access],
                shell->array[shell->array_count], env);
            exit(0);
        } else if (shell->path_access == -1) {
            execve(shell->array[shell->array_count][0],
                shell->array[shell->array_count], env);
            exit(0);
        } else {
            execve(shell->array[shell->array_count][0],
                shell->array[shell->array_count], env);
            exit(0);
        }
    }
}