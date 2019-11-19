/*
** EPITECH PROJECT, 2019
** my_atoi
** File description:
** my_atoi
*/

#include "./../../include/my.h"

int my_atoi(char *str)
{
    int longueur = my_strlen(str);
    int result = 0;

    for (int i = 0; i < longueur && longueur < 9; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            result += str[i] - '0';
            result *= 10;
        }
    }
    return (result /= 10);
}