/*
** EPITECH PROJECT, 2019
** intlen
** File description:
** intlen
*/

#include "./../../include/my.h"

int my_intlen(int nb)
{
    float float_int = nb;
    int result = 0;

    for (; float_int >= 1; float_int /= 10) {
        result++;
    }
    return (result);
}