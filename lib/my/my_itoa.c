/*
** EPITECH PROJECT, 2019
** my_itoa
** File description:
** my_itoa
*/

#include "./../../include/my.h"

char *my_itoa(int nb)
{
    char *str = malloc(sizeof(char) * 5);
    int i = 0;

    while (nb > 9) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
        i++;
    }
    str[i] = nb % 10 + 48;
    str[i + i] = '\0';
    str = my_revstr(str);
    return (str);
}//rev marche pas