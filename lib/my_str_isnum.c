/*
** EPITECH PROJECT, 2022
** isnum
** File description:
** ratio
*/

int my_str_isnum(char const *str)
{
    for (int i = 0;str[i] != '\0';i++)
        if (!(str[i] > 47 && str[i] < 58))
            return 0;
    return 1;
}
