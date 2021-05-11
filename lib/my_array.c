/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** my_array.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

char *my_strcpy_array(char *src, char *dest,
                    char delimiter, int i)
{
    int o = 0;

    while (src[i] != delimiter && src[i] != '\0') {
        dest[o] = src[i];
        i++;
        o++;
    }
    dest[o] = '\0';
    return dest;
}

int my_strlen_array(char *str, char delimiter, int i)
{
    int count = 0;

    while (str[i] != delimiter && str[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

int count_boxes(char *str, char delimiter)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == delimiter)
            count++;
    return count;
}

char **create_array(char *str, char delimiter)
{
    int i = 0;
    int c = 0;
    int box_size = 0;
    int boxes = count_boxes(str, delimiter);
    char **buffer = malloc(sizeof(char *) * (boxes + 2));

    while (i <= my_strlen(str)) {
        box_size = my_strlen_array(str, delimiter, i);
        buffer[c] = malloc(sizeof(char) * (box_size + 1));
        buffer[c] = my_strcpy_array(str, buffer[c],
                                    delimiter, i);
        i += box_size + 1;
        c++;
    }
    buffer[c] = NULL;
    return buffer;
}