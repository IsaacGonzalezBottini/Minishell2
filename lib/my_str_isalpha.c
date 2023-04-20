/*
** EPITECH PROJECT, 2022
** isalpha
** File description:
** ta mere
*/

int my_str_isalphanum(const char *str)
{
    for (int i = 0;str[i] != '\0';i++){
        int isup = str[i] > 64 && str[i] < 91;
        int islow = str[i] > 96 && str[i] < 123;
        int isnum = str[i] > 47 && str[i] < 58;
        if (!(isup || islow || isnum || str[i] == '_'))
            return 0;
        if (i == 0 && isnum)
            return 0;
    }
    return 1;
}
