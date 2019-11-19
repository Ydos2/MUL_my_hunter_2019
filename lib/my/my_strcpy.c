/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** my_strcpy
*/
#include "./../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    dest[my_strlen(src)] = '\0';

    for (char i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    return (dest);
}