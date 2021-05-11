/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** my_count_array.c
*/

#include <stdlib.h>

int my_count_array(char **buffer)
{
    int i = 0;

    for (; buffer[i] != NULL; i++);
    return i;
}