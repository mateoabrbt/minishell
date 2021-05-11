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

/*int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}*/

int my_clean_start(char *str)
{
    int i = 0;

    if (str[0] == ' ' || str[0] == '\t'
        || str[0] == ';' || str[0] == '\n')
        for (; str[i] == ' ' || str[i] == '\t'
            || str[i] == ';' || str[i] == '\n'; i++);
    return i;
}

int my_clean_end(char *str)
{
    int i = 0;
    int endstr = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != ';')
            endstr = i;
    str[endstr + 1] = '\0';
    return endstr;
}

char *my_strcpy_clean_str(char *src, char *dest, int startstr, int endstr)
{
    int i = 0;
    int o = 0;
    int temp = 0;

    for (i = startstr; i <= endstr; i++) {
        if (src[i] == ' ' || src[i] == '\t') {
            temp = i + 1;
            while ((src[temp] == ' ' || src[temp] == '\t')
                    && src[temp] != '\0') {
                if (src[temp] == ' ' || src[temp] == '\t')
                    i++;
                temp++;
            }
        }
        dest[o] = src[i];
        o++;
    }
    dest[o] = '\0';
    return dest;
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
        if (src[i + 1] == ';') {
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
    int startstr = 0;
    int endstr = 0;
    int strcount = 0;
    int size = 0;
    char *clean_str = NULL;
    char *clean_str_2 = NULL;

    startstr = my_clean_start(str);
    endstr = my_clean_end(str);
    strcount = my_strlen(str);
    size = ((strcount - startstr) - (strcount - endstr) + 2);
    clean_str = malloc(sizeof(char) * size);
    clean_str = my_strcpy_clean_str(str, clean_str, startstr, endstr);
    clean_str_2 = malloc(my_strlen(clean_str) + 1);
    clean_str_2 = my_strcpy_clean_str_2(clean_str, clean_str_2);
    return clean_str_2;
}

/*void main(int ac, char **av)
{
    char *str = NULL;

    printf("%s\n", my_clean_str(av[1]));
}*/