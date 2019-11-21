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
    if (duck->offset < 229 || duck->offset > 424 && i == 0) {
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

void pos_life(sfVector2f position_duck, sfSprite* sprite,
            duck_t *duck, ui_t *ui_struct)
{
    position_duck = sfSprite_getPosition(sprite);
    if (position_duck.x >= 2020 && duck->duck_pos_win == -100) {
        if (duck->time_to_Death == 0)
            ui_struct->player_health -= 1;
        Set_Spawn_Pos_1(sprite, ui_struct, duck);
    }
    if (position_duck.x <= -100 && duck->duck_pos_win == 2020) {
        if (duck->time_to_Death == 0)
            ui_struct->player_health -= 1;
        Set_Spawn_Pos_1(sprite, ui_struct, duck);
    }
}

void duck_die_anim(sfSprite* sprite,
            duck_t *duck, ui_t *ui_struct)
{
    if (ui_struct->seconds > 0.15) {
        move_rect_duck_die(duck, 365);
        duck->time_to_Death++;
    }
    if (duck->time_to_Death == 12) {
        Set_Spawn_Pos_1(sprite, ui_struct, duck);
        duck->time_to_Death = 0;
        duck->health = 0;
    }
}