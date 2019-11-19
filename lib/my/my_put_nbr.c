/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** my_put_nbr
*/
#include "./../../include/my.h"

int my_put_nbr_pos(int nbr)
{
    long int div = 1;

    while ((nbr / div ) != 0){
        div = div*10;
    }
    while (div != 1){
        my_putchar(((nbr%div)/(div/10)) + '0');
        div = div / 10;
    }
    return (0);
}

int my_put_nbr_neg(int nbr)
{
    long int div = 1;

    my_putchar('-');
    nbr = -nbr;
    while ((nbr / div ) != 0){
        div = div*10;
    }
    while (div != 1){
        my_putchar(((nbr%div)/(div/10)) + '0');
        div = div / 10;
    }
    return (0);
}

int my_put_nbr(int nbr)
{
    if (nbr > 0){
        my_put_nbr_pos(nbr);
    } else if (nbr < 0){
        my_put_nbr_neg(nbr);
    } else {
        my_putchar('0');
    }
    return (0);
}