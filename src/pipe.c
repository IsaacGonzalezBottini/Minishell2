/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/

#include"minishell.h"

int check_for_pipe(char *command)
{
    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == '|')
            return 1;
    }
    return 0;
}

int create_pipe(char **command, char **command2, char **env, int *status)
{
    int pipefd[2];
    int sdin = dup(STDIN_FILENO);
    int sdout = dup(STDOUT_FILENO);
    int st;
    pipe(pipefd);
    pid_t pid = fork();
    if (pid == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        execute_command(command2, env, status);
        dup2(sdin, STDIN_FILENO);
        close(pipefd[0]);
    } else {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        execute_command(command, env, status);
        dup2(sdout, STDOUT_FILENO);
        close(pipefd[1]);
        waitpid(pid, status, 0);
    }
}

void execute_with_pipe(char **command, char **env, int *status)
{
    char **command2 = NULL;
    for (int i = 0; command[i]; i++) {
        if (command[i][0] == '|') {
            command2 = &command[i + 1];
            command[i] = NULL;
            break;
        }
    }
    create_pipe(command, command2, env, status);
}
