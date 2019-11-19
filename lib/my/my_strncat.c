/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** my_strncat
*/
#include "./../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    char a = my_strlen(dest);

    for (char b = 0; b < nb; b++) {
        dest[a] = src[b];
        a++;
    }
        return (dest);
}