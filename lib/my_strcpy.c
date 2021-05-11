/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** my_strcpy.c
*/

char *my_strcpy(char *src, char *dest)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}