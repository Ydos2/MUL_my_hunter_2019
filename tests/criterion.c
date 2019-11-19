/*
** EPITECH PROJECT, 2019
** criterion
** File description:
** criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, twitter, .init = redirect_all_std)
{
    my_printf("Address of a: %#X\n", 18295);
    cr_assert_stdout_eq_str("Address of a: 0X4777");
}