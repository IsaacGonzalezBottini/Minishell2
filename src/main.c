/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/

#include"minishell.h"

void print_dec(char *pwd)
{
    write(1, "[", 1);
    write(1, my_str_end_of_path(pwd), my_strlen(my_str_end_of_path(pwd)));
    write(1, "] ", 2);
    write(1, "$> ", 3);
}

void shell_loop(char **env, int *status)
{
    char *buffer = NULL;
    char **line = NULL;
    size_t len = 0;
    int test_getline = 0;
    char pwd[256];
    getcwd(pwd, sizeof(pwd));
    while (1) {
        if (isatty(0))
            print_dec(pwd);
        test_getline = getline(&buffer, &len, stdin);
        line = my_str_to_word_array(buffer, ";");
        if (test_getline == -1)
            return;
        for (int i = 0; line[i] != NULL; i++) {
            launch_command(line[i], env, status);
        }
        getcwd(pwd, sizeof(pwd));
    }
}

int main(int ac, char **av, char **env)
{
    ac = 0;
    av = NULL;
    int status = 0;
    shell_loop(env, &status);
    return status;
}
