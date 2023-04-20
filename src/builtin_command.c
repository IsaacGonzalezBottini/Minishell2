/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/

#include"minishell.h"

int builtin_exit(char **command, char **env)
{
    exit(0);
    return 0;
}

int builtin_env(char **command, char **env)
{
    print_env(env);
    return 0;
}

int builtin_setenv(char **command, char **env)
{
    return setenv_var(env, command[1], command[2], 0);
}

int builtin_unsetenv(char **command, char **env)
{
    unsetenv_var(env, command[1]);
    return 0;
}

int builtin_cd(char **command, char **env)
{
    char pwd[256];
    if (command[1] == NULL || command[1][0] == '~') {
        chdir("/");
        return 0;
    }
    if (command[1][0] == '-' && command[1][1] == '\0') {
        char *old = my_strcpy(get_env_var(env, "OLDPWD"));
        if (old == NULL) {
            write(2, ": No such file or directory.\n", 29);
            return 0;
        }
        getcwd(pwd, sizeof(pwd));
        setenv_var(env, "OLDPWD", pwd, 0);
        chdir(old);
        return 0;
    }
    return execute_cd(command, env, pwd);
}
