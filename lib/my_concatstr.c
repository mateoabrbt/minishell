/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** my_concatstr.c
*/

char *my_concatstr(char *src1, char *src2, char *dest)
{
    int c = 0;

    for (int i = 0; src1[i] != '\0'; i++, c++)
        dest[c] = src1[i];
    for (int i = 0; src2[i] != '\0'; i++, c++)
        dest[c] = src2[i];
    dest[c] = '\0';
    return (dest);
}