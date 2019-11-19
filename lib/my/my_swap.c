/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swaps content of two variables
*/
#include "./../../include/my.h"

void my_swap(int *a, int *b)
{
    int c = *b;
    *b = *a;
    *a = c;
}