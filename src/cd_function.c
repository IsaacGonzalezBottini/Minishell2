/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/

#include"minishell.h"

int is_folder(char *path)
{
    struct stat sb;
    stat(path, &sb);
    return S_ISDIR(sb.st_mode);
}

int execute_cd(char **command, char **env, char *pwd)
{
    if (!is_folder(command[1])) {
        write(2, command[1], my_strlen(command[1]));
        write(2, ": Not a directory.\n", 19);
        return 1;
    }
    getcwd(pwd, sizeof(pwd));
    setenv_var(env, "OLDPWD", pwd, 0);
    chdir(command[1]);
    return 0;
}
