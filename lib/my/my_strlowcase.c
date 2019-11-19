/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** my_strlowcase
*/
#include "./../../include/my.h"

char *my_strlowcase(char *str)
{
    for (char a = 0; str[a] != '\0'; a++)
        if (str[a] >= 'A' && str[a] <= 'Z')
            str[a] += 32;
    return (str);
}