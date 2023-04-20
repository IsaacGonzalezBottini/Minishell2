/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** return the len of a string
*/

#include<stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

int my_strcont(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int my_strcmp(char *c, char *d)
{
    if (my_strlen(c) != my_strlen(d))
        return 0;
    for (int i = 0; c[i] != '\0';i++)
        if (c[i] != d[i])
        return 0;
    return 1;
}

int my_strncmp(char *c, char *d, int n)
{
    for (int i = 0; c[i] != '\0' || i == n - 1 ;i++)
        if (c[i] != d[i])
            return 0;
    return 1;
}

char *my_str_end_of_path(char *str)
{
    if (str[0] == '/' && str[1] == '\0')
        return str;
    char *rslt = NULL;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '/')
            rslt = &str[i + 1];
    }
    return rslt;
}
