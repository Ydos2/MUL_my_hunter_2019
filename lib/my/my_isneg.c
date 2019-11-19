/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** my_isneg
*/
#include "./../../include/my.h"

int my_isneg(int n)
{
    if (n < 0)
        write(1, &"N", 1);
    else
        write(1, &"P", 1);
    return (0);
}