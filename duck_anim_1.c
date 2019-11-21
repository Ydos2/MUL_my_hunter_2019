/*
** EPITECH PROJECT, 2019
** duck_anim
** File description:
** duck_anim_1
*/

#include "include/frambuffer.h"
#include "include/my.h"

void move_rect_duck(duck_t *duck, int max_value)
{
    int i = 0;

    if (duck->offset > 90 && i == 0) {
        duck->offset = 0;
        i++;
    }
    if (duck->offset == 0 && i == 0) {
        duck->offset = 40;
        i++;
    }
    if (duck->offset == 40 && i == 0) {
        duck->offset = 80;
        i++;
    }
    if (duck->offset == 80 && i == 0)
        duck->offset = 0;
}

void move_rect_duck_die(duck_t *duck, int max_value)
{
    int i = 0;

    if (duck->offset == 230 || duck->offset == 345 && i == 0) {
        duck->offset = 275;
        i++;
    }
    if(duck->offset < 229 || duck->offset > 424 && i == 0) {
        duck->offset = 230;
        i++;
    }
    if (duck->offset == 275 && i == 0) {
        duck->offset = 296;
        i++;
    }
    if (duck->offset == 296 && i == 0) {
        duck->offset = 320;
        i++;
    }
    if (duck->offset == 320 && i == 0)
        duck->offset = 345;
}

void move_rect_duck_flip(duck_t *duck, int max_value)
{
    int i = 0;

    if (duck->offset < 424 && i == 0) {
        duck->offset = 425;
        i++;
    }
    if (duck->offset == 425 && i == 0) {
        duck->offset = 465;
        i++;
    }
    if (duck->offset == 465 && i == 0) {
        duck->offset = 505;
        i++;
    }
    if (duck->offset == 505 && i == 0)
        duck->offset = 425;
}