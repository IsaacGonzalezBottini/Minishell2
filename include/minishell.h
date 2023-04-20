/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/


#ifndef MINISHELL_H_
    #define MINISHELL_H_

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <string.h>
    #include <errno.h>
    #include <signal.h>
    #include <fcntl.h>


    #define err_setenv_varname "setenv: Variable name must contain \
alphanumeric characters.\n"

char **my_str_to_word_array(char *str, char *separators);
char *my_strcat(char *dest, char *src);
int my_strlen(char const *str);
int my_strcmp(char *c, char *d);
char *my_str_end_of_path(char *str);
int my_strncmp(char *c, char *d, int n);
int my_str_isalphanum(const char *str);
int my_strcont(char *str, char c);
char *my_strcpy(char *str);

char *get_env_var(char **env, char *var);
void print_env(char **env);
int setenv_var(char **env, char *var, char *content, int i);
void unsetenv_var(char **env, char* var);

int execute_command(char **command, char **env, int *status);

int builtin_exit(char **command, char **env);
int builtin_env(char **command, char **env);
int builtin_setenv(char **command, char **env);
int builtin_cd(char **command, char **env);
int builtin_unsetenv(char **command, char **env);

void launch_command(char *com, char **env, int *status);

int is_folder(char *path);
int execute_cd(char **command, char **env, char *pwd);

void error_message(int status);

int my_str_isalphanum(const char *str);

int check_for_pipe(char *command);
void execute_with_pipe(char **command, char **env, int *status);
char *separate_on_char(char *str, char separated_on, char separator);

int redirect_left(char *file, int simple);

struct stfctb {
    char *name;
    int (*fct) (char**,char**);
};

#endif
