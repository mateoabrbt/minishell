/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** test_path.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "lib.h"

void create_new_path(t_minishell *shell)
{
    int size1 = 0;
    int size2 = 0;
    char *arg = NULL;
    char *path = NULL;

    size1 = my_strlen(shell->array[shell->array_count][0]);
    arg = malloc(sizeof(char) * (size1 + 2));
    arg = my_concatstr("/", shell->array[shell->array_count][0], arg);
    for (int c = 0; shell->paths[c] != NULL; c++) {
        path = malloc(sizeof(char) * (my_strlen(shell->paths[c]) + 1));
        path = my_strcpy(shell->paths[c], path);
        size1 =  my_strlen(arg);
        size2 = my_strlen(path);
        shell->paths[c] = malloc(sizeof(char) * (size1 + size2 + 1));
        shell->paths[c] = my_concatstr(path, arg, shell->paths[c]);
    }
    free(path);
    free(arg);
}

void test_path(t_minishell *shell)
{
    if (access(shell->array[shell->array_count][0], X_OK) == 0)
        shell->path_access = -1;
    else {
        create_new_path(shell);
        for (shell->path_access = 0; shell->paths[shell->path_access]
                != NULL; shell->path_access++) {
            if (access(shell->paths[shell->path_access], X_OK) == 0)
                break;
            if (access(shell->paths[shell->path_access], X_OK) == -1
                && shell->paths[shell->path_access + 1] == NULL
                && shell->array[shell->array_count][0][0] != '\n') {
                my_puterror(shell->array[shell->array_count][0]);
                my_puterror(": Command not found.\n");
            }
        }
    }
}