/*
** EPITECH PROJECT, 2023
** Ressources
** File description:
** Ressources
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    if (dest == NULL) {
        return src;
    }
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    for (i = 0 ; i < my_strlen(dest) ; ++i) {
        str[i] = dest[i];
    }
    for (i = 0 ; i < my_strlen(src) ; ++i) {
        str[i + my_strlen(dest)] = src[i];
    }
    str[i + my_strlen(dest)] = '\0';
    return str;
}
