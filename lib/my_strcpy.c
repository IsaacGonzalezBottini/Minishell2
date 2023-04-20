/*
** EPITECH PROJECT, 2023
** Ressources
** File description:
** Ressources
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *str)
{
    char *nstr = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; str[i] != '\0'; i++)
        nstr[i] = str[i];
    nstr[my_strlen(str)] = '\0';
    return nstr;
}
