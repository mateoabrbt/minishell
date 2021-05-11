/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** display_minishell.c
*/

#include "lib.h"
#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void display_minishell(void)
{
    int i = 0;
    int o = 0;
    size_t sizedir = 0;
    char *bufferdir = NULL;

    bufferdir = getcwd(bufferdir, sizedir);
    while (bufferdir[i] != '\0') {
        i++;
        if (bufferdir[i] == '/')
            o = i;
    }
    o++;
    my_putstr("[minishell@localhost ");
    while (bufferdir[o] != '\0') {
        my_putchar (bufferdir[o]);
        o++;
    }
    my_putstr("]$ > ");
    free(bufferdir);
}