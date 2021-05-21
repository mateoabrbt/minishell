/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** minishell.h
*/

#ifndef MINISHELL
#define MINISHELL

typedef struct minishell_structure
{
    int array_count;
    int home_status;
    int path_access;
    char *arg;
    char *home;
    char *env_empty;
    int env_status;
    char **paths;
    char ***array;
}t_minishell;

typedef struct pointer_structure_void
{
    char *arg;
    void (*function)(t_minishell *shell, char **env);
}t_handle_args_void;

typedef struct pointer_structure_char
{
    char *arg;
    char **(*function)(t_minishell *shell, char **env);
}t_handle_args_char;

int minishell(char **env);
void display_minishell(void);
void test_path(t_minishell *shell);
void free_minishell(t_minishell *shell);
void minishell_init(t_minishell *shell);
void fill_struct(t_minishell *shell, char **env);
void exec_program(t_minishell *shell, char **env);
void env_minishell(t_minishell *shell, char **env);
void exit_minishell(t_minishell *shell, char **env);
void clean_minishell(t_minishell *shell, char **env);
char *modify_env(char *dest, char *str, char *str2, char *str3);
char **clean_env(char **env);
char **handle_arg(t_minishell *shell, char **env);
char **cd_minishell(t_minishell *shell, char **env);
char **setenv_minishell(t_minishell *shell, char **env);
char **unsetenv_minishell(t_minishell *shell, char **env);
char **change_pwd_oldpwd(char *oldpwd, char *pwd, char **env);

#endif /* !MINISHELL */