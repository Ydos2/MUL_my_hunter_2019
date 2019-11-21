/*
** EPITECH PROJECT, 2019
** duck_script_ai
** File description:
** duck_script_ai
*/

#include "include/frambuffer.h"
#include "include/my.h"

void Set_Spawn_Pos_1(sfSprite* sprite, ui_t *ui_struct, duck_t *duck)
{
    sfVector2f duck_pos;
    int x = (rand() % 10);

    ui_struct->duck_pos_val = x;
    switch (x) {
    case 0:
        duck_pos.x = -100, duck_pos.y = 0, duck->duck_pos_win = -100;
        break;
    case 1:
        duck_pos.x = -100, duck_pos.y = 100, duck->duck_pos_win = -100;
        break;
    case 2:
        duck_pos.x = -100, duck_pos.y = 200, duck->duck_pos_win = -100;
        break;
    case 3:
        duck_pos.x = -100, duck_pos.y = 300, duck->duck_pos_win = -100;
        break;
    }
    Set_Spawn_Pos_2(x, sprite, duck, duck_pos);
}

void Set_Spawn_Pos_2(int x, sfSprite* sprite, duck_t *duck,
                    sfVector2f duck_pos)
{
    switch (x) {
    case 4:
        duck_pos.x = -100, duck_pos.y = 400, duck->duck_pos_win = -100;
        break;
    case 5:
        duck_pos.x = -100, duck_pos.y = 500, duck->duck_pos_win = -100;
        break;
    case 6:
        duck_pos.x = 2020, duck_pos.y = 0, duck->duck_pos_win = 2020;
        break;
    case 7:
        duck_pos.x = 2020, duck_pos.y = 125, duck->duck_pos_win = 2020;
        break;
    case 8:
        duck_pos.x = 2020, duck_pos.y = 250, duck->duck_pos_win = 2020;
        break;
    }
    Set_Spawn_Pos_3(x, sprite, duck, duck_pos);
}

void Set_Spawn_Pos_3(int x, sfSprite* sprite, duck_t *duck,
                    sfVector2f duck_pos)
{
    switch (x) {
    case 9:
        duck_pos.x = 2020, duck_pos.y = 375, duck->duck_pos_win = 2020;
        break;
    case 10:
        duck_pos.x = 2020, duck_pos.y = 500, duck->duck_pos_win = 2020;
        break;
    default:
        break;
    }
    sfSprite_setPosition(sprite, duck_pos);
}