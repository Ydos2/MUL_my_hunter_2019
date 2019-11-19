/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** my_str_isupper
*/
#include "./../../include/my.h"

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!(str[i] > 64 && str[i] < 91))
            return (1);
        i++;
    }
    if (str[0] == '\0')
        return (1);
    else
        return (0);
}