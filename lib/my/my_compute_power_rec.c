/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/
#include "./../../include/my.h"

int my_compute_power_rec(int nb, int p)
{
    int temp = 0;

    if (nb == 0 && p != 0 || p < 0)
        return (0);
    if (p == 1)
        return (nb);
    else if (p == 0)
        return (1);
    else {
        temp = nb * my_compute_power_rec(nb, p - 1);
        if (nb > 0 && temp < 2147483648 && temp > 0)
            return (temp);
        if (nb < 0 && temp > -2147483649)
            return (temp);
        else
        return (0);
    }
}