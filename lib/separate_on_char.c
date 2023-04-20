/*
** EPITECH PROJECT, 2022
** isalpha
** File description:
** separate on char func
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int my_strlen(char const *str);

int check_nb_of_char_in_str(char *str, char c)
{
    int nb = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            nb++;
    }
    return nb;
}

char *separate_on_char(char *str, char separated_on, char separator)
{
    char *nstr = malloc(sizeof(char) * (my_strlen(str) +
    check_nb_of_char_in_str(str, separated_on) * 2));
    int c = 0;
    int i = 0;
    for (; str[i] != '\0'; i++) {
        nstr[i + c] = str[i];
        if (str[i + 1] == separated_on) {
            nstr[i + 1 + c] = separator;
            c++;
        }
        if (nstr[i + c] == separated_on) {
            nstr[i + 1 + c] = separator;
            c++;
        }
    }
    nstr[i + c] = '\0';
    return nstr;
}
