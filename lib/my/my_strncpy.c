/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** my_strncpy
*/
#include "./../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (char a = 0; a != n; a++ )
        dest[a] = src[a];
    return (dest);
}