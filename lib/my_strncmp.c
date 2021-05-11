/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** my_check_str.c
*/

#include "lib.h"

int my_strncmp(char *str1, char *str2,
            char delimiter1, char delimiter2)
{
    int i = 0;
    int j = 0;
    int a = my_strnlen(str1, delimiter1);
    int b = my_strnlen(str2, delimiter2);

    if (a == b) {
        while (str1[i] != delimiter1 && str2[j] != delimiter2) {
            if (str1[i] == str2[j]) {
                i++;
                j++;
            } else
                return (0);
        }
        return (1);
    } else
        return (0);
}