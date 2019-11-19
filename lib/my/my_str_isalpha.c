/*
** EPITECH PROJECT, 2019
** my_str_isakpha
** File description:
** my_str_isalpha
*/
#include "./../../include/my.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!(str[i] >= 'a' && str[i] <= 'z')
        || !(str[i] >= 'A' && str[i] <= 'Z'))
            return (1);
        i++;
    }
    if (str[0] == '\0')
        return (1);
    else
        return (0);
}