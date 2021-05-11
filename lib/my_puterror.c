/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** my_puterror.c
*/

#include <unistd.h>

void my_puterror(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
}