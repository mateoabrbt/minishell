/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** my_triple_array.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

char *my_strcpy_array(char *src, char *dest,
                    char delimiter, int i);

int my_strlen_array(char *str, char delimiter, int i);

int count_boxes(char *str, char delimiter);

char ***create_triple_array(char *str, char delimiter)
{
    int i = 0;
    int c = 0;
    char *tmp = NULL;
    int box_size = 0;
    int boxes = count_boxes(str, delimiter);
    char ***buffer = malloc(sizeof(char **) * (boxes + 2));

    while (i <= my_strlen(str)) {
        box_size = my_strlen_array(str, delimiter, i);
        tmp = malloc(sizeof(char) * (box_size + 1));
        tmp = my_strcpy_array(str, tmp, delimiter, i);
        buffer[c] = create_array(tmp, ' ');
        i += box_size + 1;
        c++;
    }
    buffer[c] = NULL;
    return buffer;
}