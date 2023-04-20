/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/

#include"minishell.h"

void print_env(char **env)
{
    for (int i = 0; env[i];i++) {
        write(1, env[i], my_strlen(env[i]));
        write(1, "\n", 1);
    }
}

char *get_env_var(char **env, char *var)
{
    if (var == NULL)
        return NULL;
    int len = my_strlen(var);
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(my_strcat(var, "="), env[i], len) == 1) {
            return &env[i][len + 1];
        }
    }
    return NULL;
}

int add_env_var(char **env, char *content, char *var)
{
    int i = 0;
    for (i = 0; env[i]; i++);
    env[i] = my_strcat(var, my_strcat("=", content == NULL ? "" : content));
    env[i + 1] = NULL;
    return 0;
}

int setenv_var(char **env, char *var, char *content, int i)
{
    if (var == NULL) {
        print_env(env);
        return 0;
    }
    if (!my_str_isalphanum(var)) {
        write(2, err_setenv_varname, my_strlen(err_setenv_varname));
        return 1;
    }
    char *c = get_env_var(env, var);
    if (c != NULL) {
        if (content == NULL) {
            c[0] = '\0';
            return 0;
        }
        for (i = 0; content[i] != '\0'; i++)
            c[i] = content[i];
        c[i] = '\0';
        return 0;
    }
    return add_env_var(env, content, var);
}

void unsetenv_var(char **env, char* var)
{
    if (var == NULL)
        return;
    int len = my_strlen(var);
    int i = 0;
    for (i = 0; env[i]; i++) {
        if (my_strncmp(my_strcat(var, "="), env[i], len) == 1) {
            break;
        }
    }
    if (env[i] == NULL)
        return;
    for (int j = i; env[j]; j++) {
        env[j] = env[j + 1];
    }
}
