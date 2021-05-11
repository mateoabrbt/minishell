/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}