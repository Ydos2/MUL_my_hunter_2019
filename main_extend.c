/*
** EPITECH PROJECT, 2019
** main_extend
** File description:
** main_extend
*/

#include "include/frambuffer.h"
#include "include/my.h"

void main_extend_1(sfRenderWindow *window, ui_t *ui_struct, sfClock *clock)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    clock_func(clock, ui_struct);
    draw_background_up(window);
}