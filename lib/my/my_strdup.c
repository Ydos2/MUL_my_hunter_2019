/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** my_strdup
*/
#include "./../../include/my.h"

char *my_strdup(char const *src)
{
    int src_len = my_strlen(src);
    char *res;

    res = malloc(src_len * sizeof(char));
    my_strcpy(res, src);
    return (res);
}