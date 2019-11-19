/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** my_revstr
*/
#include "./../../include/my.h"

char my_compt(char *str)
{

    char i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i = 0, j = 0;
    char tmp;

    while (str[j] != '\0') {
        j++;
    }
    j--;
    while (i < j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i = i + 1;
        j = j - 1;
    }
    return (str);
}