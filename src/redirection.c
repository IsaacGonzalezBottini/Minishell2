/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/

#include"minishell.h"

int clean_redirection_char(char **command, int i)
{
    for (int j = 0; command[i][j] != '\0'; j++) {
        if ((command[i][j] == '>' || command[i][j] == '<') && i != 0) {
            command[i] = NULL;
            return 0;
        }
        if (command[i][j] == '>' || command[i][j] == '<') {
            command[i][j] = '\0';
            return 0;
        }
    }
}

int clean_redirection(char **command)
{
    for (int i = 0; command[i]; i++) {
        clean_redirection_char(command, i);
    }
}

int redirect(char *file, int simple)
{
    int len = 0;
    char *name;
    int fd;
    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == '>') {
            break;
        }
        len = i + 1;
    }
    name = malloc(sizeof(char) * (len + 1));
    name[len] = '\0';
    for (int i = 0; i < len; i++)
        name[i] = file[i];
    if (simple == 1)
        fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (simple == 0)
        fd = open(name, O_RDWR | O_CREAT | O_APPEND, 0644);
    free(name);
    dup2(fd, 1);
    return fd;
}

int check_redirection(char **command)
{
    char *com = malloc(sizeof(char) * 256);
    int c = 0;
    int fd = -1;
    for (int i = 0; command[i]; i++)
        for (int j = 0; command[i][j] != '\0'; j++) {
            com[c] = command[i][j];
            c++;
        }
    com[c] = '\0';
    for (int i = 0; com[i] != '\0'; i++) {
        if (i > 0 && com[i] == '>' && com[i - 1] != '>' && com[i + 1] != '>')
            fd = redirect(&com[i + 1], 1);
        if (i > 0 && com[i] == '<' && com[i - 1] != '<' && com[i + 1] != '<')
            fd = redirect_left(&com[i + 1], 1);
        if (i > 0 && com[i] == '<' && com[i - 1] != '<' && com[i + 1] == '<')
            fd = redirect_left(&com[i + 1], 0);
        if (i > 0 && com[i] == '>' && com[i - 1] != '>' && com[i + 1] == '>')
            fd = redirect(&com[i + 2], 0);
    }
    return fd;
}

void launch_command(char *com, char **env, int *status)
{
    int sdout = dup(1);
    int sdin = dup(0);
    char **command;
    com = separate_on_char(com, '|', ' ');
    command = my_str_to_word_array(com, " \n\t");
    int fd = check_redirection(command);
    clean_redirection(command);
    if (check_for_pipe(com) == 0)
        execute_command(command, env, status);
    else
        execute_with_pipe(command, env, status);
    dup2(sdin, 0);
    dup2(sdout, 1);
}
