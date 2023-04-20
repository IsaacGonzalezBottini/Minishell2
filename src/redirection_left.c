/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/

#include"minishell.h"

int double_left_redirection(char *eof)
{
    int fd = open("/tmp/dblrd", O_CREAT | O_RDWR | O_TRUNC, 0644);
    int test = 0;
    char *buffer;
    size_t len;
    for (int i = 0; test != -1; i++) {
        write(1, "> ", 2);
        getline(&buffer, &len, stdin);
        if (my_strncmp(eof, buffer, my_strlen(eof)) == 1)
            break;
        else
            write(fd, buffer, my_strlen(buffer));
    }
    close(fd);
    fd = open("/tmp/dblrd", O_RDWR, 0644);
    dup2(fd, 0);
}

int redirect_left(char *file, int simple)
{
    if (simple == 0) {
        double_left_redirection(&file[1]);
        return 0;
    }
    int len = 0;
    int fd;
    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == '<')
            break;
        len = i + 1;
    }
    char *name = malloc(sizeof(char) * (len + 1));
    name[len] = '\0';
    for (int i = 0; i < len; i++)
        name[i] = file[i];
    if (simple == 1)
        fd = open(name, O_RDWR, 0644);
    free(name);
    dup2(fd, 0);
    return fd;
}
