/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/

#include"minishell.h"

int is_builtin(char **command, char **env, int *status)
{
    static struct stfctb builtin_fct[] = {
        {"cd", builtin_cd},
        {"exit", builtin_exit},
        {"env", builtin_env},
        {"setenv", builtin_setenv},
        {"unsetenv",builtin_unsetenv},
        {"", NULL}
    };
    for (int i = 0; builtin_fct[i].fct != NULL;i++) {
        if (my_strcmp(command[0], builtin_fct[i].name)) {
            *status = builtin_fct[i].fct(command, env);
            return 1;
        }
    }
    return 0;
}

char *search_in_folder(DIR *d, struct dirent *dirt, char *com, char *pr)
{
    while ((dirt = readdir(d)) != NULL) {
        if (dirt->d_type == DT_REG && my_strcmp(com, dirt->d_name))
            return my_strcat(pr, my_strcat("/", dirt->d_name));
    }
    return NULL;
}

void get_executable_path(char **env, char **command, int *status)
{
    char **path = my_str_to_word_array(get_env_var(env, "PATH"), ":");
    DIR *dir = NULL;
    struct dirent *dirt;
    char *rslt = NULL;
    for (int i = 0; path[i]; i++) {
        while ((dir = opendir(path[i])) == NULL)
            i++;
        rslt = search_in_folder(dir, dirt, command[0], path[i]);
        if (rslt != NULL) {
            command[0] = rslt;
            closedir(dir);
            return;
        }
        closedir(dir);
    }
    write(2, command[0], my_strlen(command[0]));
    write(2, ": Command not found.\n", 21);
    *status = 1;
    command[0] = NULL;
}

int execute_execve(char **command, char **env, int *exit_status)
{
    pid_t pid;
    int status;
    if (command[0] == NULL)
        return 0;
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execve(command[0], command, env);
        exit(EXIT_FAILURE);
    } else {
        wait(&status);
        *exit_status = status;
        error_message(*exit_status);
    }
}

int execute_command(char **command, char **env, int *status)
{
    if (command[0] == NULL)
        return 0;
    if (is_builtin(command, env, status))
        return 0;
    if (!my_strcont(command[0], '/')) {
        get_executable_path(env, command, status);
    }
    if (command[0] == NULL) {
        return 1;
    }
    execute_execve(command, env, status);
}
