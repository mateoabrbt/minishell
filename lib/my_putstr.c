/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** my_putstr.c
*/

#include <unistd.h>

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write (1, &str[i], 1);
}