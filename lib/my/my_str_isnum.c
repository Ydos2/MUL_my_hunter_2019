/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** my_str_isnum
*/
#include "./../../include/my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!(str[i] > 47 && str[i] < 58))
            return (1);
        i++;
    }
    if (str[0] == '\0')
        return (1);
    else
        return (0);
}