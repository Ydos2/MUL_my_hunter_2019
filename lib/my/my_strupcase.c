/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** my_strupcase
*/
#include "./../../include/my.h"

char *my_strupcase(char *str)
{
    for (char a = 0; str[a] != '\0'; a++)
        if (str[a] >= 'a' && str[a] <= 'z')
            str[a] -= 32;
    return (str);
}