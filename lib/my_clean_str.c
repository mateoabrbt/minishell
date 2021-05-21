/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** clean_str.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

char *remove_char(char *str, int o)
{
    char *new_str = str;

    for (int i = o; str[i] != '\0'; i += 1)
        str[i] = new_str[i + 1];
    return str;
}

char *my_strcpy_clean_str(char *str)
{
    int size = 0;

    for (int i = 0; str[i] != '\n' && str[i] != '\0'; ++i) {
        if ((str[i] == ' ' || str[i] == '\t')
                && (i == 0 || str[i + 1] == ' ' || str[i + 1] == '\t'
                || str[i + 1] == '\0' || str[i + 1] == '\n')) {
            str = remove_char(str, i--);
        } else if (str[i] == '\t')
            str[i] = ' ';
    }
    size = my_strlen(str);
    str[size - 1] = '\0';
    return str;
}

char *my_strcpy_clean_str_2(char *src, char *dest)
{
    int i;
    int o = 0;
    int temp = 0;

    for (i = 0; src[i] != '\0'; i++, o++) {
        if (i > 0)
            if (src[i - 1] == ';') {
                temp = i;
                if (src[temp] == ' ')
                    i += 1;
            }
        else if (src[i + 1] == ';') {
            temp = i;
            if (src[temp] == ' ')
                i += 1;
        }
        dest[o] = src[i];
    }
    dest[o] = '\0';
    return dest;
}

char *my_clean_str(char *str)
{
    char *clean_str = NULL;
    char *clean_str_2 = NULL;

    clean_str = my_strcpy_clean_str(str);
    clean_str_2 = malloc(my_strlen(clean_str) + 1);
    clean_str_2 = my_strcpy_clean_str_2(clean_str, clean_str_2);
    return clean_str_2;
}