/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** my_strnlen.c
*/

int my_strnlen(char *str, char delimiter)
{
    int i = 0;

    for (; str[i] != delimiter; i++);
    return i;
}