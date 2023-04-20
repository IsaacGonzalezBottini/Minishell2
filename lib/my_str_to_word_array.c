/*
** EPITECH PROJECT, 2023
** str to word array
** File description:
** str to word array
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int is_sep(char c, char *separators)
{
    for (int i = 0; separators[i] != '\0';i++)
        if (separators[i] == c || c == '\0')
            return 1;
    return 0;
}

int get_word_len(char *w, char *sep)
{
    int len = 0;
    for (int i = 0; !is_sep(w[i], sep);i++)
        len++;
    return len;
}

void fill_word(char *w, char *str, int len)
{
    for (int i = 0; i < len; i++)
        w[i] = str[i];
}

void fill(char **tab, char *str, char *sep, int words)
{
    int clen = 0;
    int cword = 0;
    for (int i = 0; cword != words; i++) {
        if (!is_sep(str[i], sep)) {
            clen = get_word_len(&str[i], sep);
            tab[cword] = malloc(sizeof(char) * (clen + 1));
            fill_word(tab[cword], &str[i], clen);
            tab[cword][clen] = '\0';
            i += clen;
            cword++;
        }
    }
}

char **my_str_to_word_array(char *str, char *separators)
{
    int nb_words = 0;
    for (int i = 0; str[i] != '\0';i++)
        if (!is_sep(str[i], separators) && is_sep(str[i + 1], separators))
            nb_words++;
    char **tab = malloc(sizeof(char*) * (nb_words + 1));
    tab[nb_words] = NULL;
    fill(tab, str, separators, nb_words);
    return tab;
}
