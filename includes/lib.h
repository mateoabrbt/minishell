/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** lib.h
*/

#ifndef LIB
#define LIB

void my_putchar(char c);
void my_putstr(char *str);
void my_puterror(char *str);
int my_strlen(char *str);
int my_count_array(char **buffer);
int my_triple_arraylen(char ***array);
int my_strnlen(char *str, char delimiter);
int my_strncmp(char *str1, char *str2,
    char delimiter1, char delimiter2);
char *my_clean_str(char *str);
char *my_strcpy(char *src, char *dest);
char *my_concatstr(char *src1, char *src2, char *dest);
char **create_array(char *str, char delimiter);
char ***create_triple_array(char *str, char delimiter);


#endif /* !LIB */