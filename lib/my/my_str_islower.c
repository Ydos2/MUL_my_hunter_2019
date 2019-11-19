/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** my_str_islower
*/
#include "./../../include/my.h"

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (!(str[i] > 96 && str[i] < 123))
            return (1);
        i++;
    }
    if (str[0] == '\0')
        return (1);
    else
        return (0);
}