/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/
#include "./../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_length = my_strlen(dest);
    int a = 0;

    while (src[a] != '\0'){
        dest[dest_length + a] = src[a];
        a++;
    }
    dest[dest_length + a] = '\0';
    return (dest);
}