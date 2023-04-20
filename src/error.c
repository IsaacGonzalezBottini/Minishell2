/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/

#include"minishell.h"

void error_message(int status)
{
    if (status == 139)
        write(2, "Segmentation fault\n", 19);
    if (status == 136)
        write(2, "Floating exception\n", 19);
}
