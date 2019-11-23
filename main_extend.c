/*
** EPITECH PROJECT, 2019
** main_extend
** File description:
** main_extend
*/

#include "include/frambuffer.h"
#include "include/my.h"

void main_extend_1(sfRenderWindow *window, ui_t *ui_struct)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    clock_func(ui_struct);
    draw_background_up(window);
}

void main_extend_2(ui_t *ui_struct, duck_t *duck)
{
    sfVideoMode mode = {1920, 1080, 32};

    ui_struct->clock = sfClock_create();
    ui_struct->window = sfRenderWindow_create(
        mode, "Duck Hunt", sfResize | sfClose, NULL);
    ui_struct->texture = create_texture_1(ui_struct->texture);
    ui_struct->sprite = create_sprite_1(
        ui_struct->sprite, ui_struct->texture);
    music_game(ui_struct);
    val_start(duck, ui_struct);
    ui_struct->menu = 1, ui_struct->player_health = 0;
    Set_Spawn_Pos_1(ui_struct->sprite, ui_struct, duck);
    sfRenderWindow_setFramerateLimit(ui_struct->window, 30);
}

void move_ai_up(sfSprite* sprite, duck_t *duck, ui_t *ui_struct)
{
    sfVector2f position_duck;

    if (ui_struct->duck_pos_val == 0)
        move_duck_up(sprite, position_duck, 22, 16);
    if (ui_struct->duck_pos_val == 1)
        move_duck_up(sprite, position_duck, 22, 8);
    if (ui_struct->duck_pos_val == 2)
        move_duck_up(sprite, position_duck, 22, 0);
    if (ui_struct->duck_pos_val == 3)
        move_duck_up(sprite, position_duck, 22, 4);
    if (ui_struct->duck_pos_val == 4)
        move_duck_up(sprite, position_duck, 22, -8);
    if (ui_struct->duck_pos_val == 5)
        move_duck_up(sprite, position_duck, 22, -16);
}

void move_ai_down(sfSprite* sprite, duck_t *duck, ui_t *ui_struct)
{
    sfVector2f position_duck;

    if (ui_struct->duck_pos_val == 6)
        move_duck_down(sprite, position_duck, 22, 16);
    if (ui_struct->duck_pos_val == 7)
        move_duck_down(sprite, position_duck, 22, 10);
    if (ui_struct->duck_pos_val == 8)
        move_duck_down(sprite, position_duck, 22, 0);
    if (ui_struct->duck_pos_val == 9)
        move_duck_down(sprite, position_duck, 22, -10);
    if (ui_struct->duck_pos_val == 10)
        move_duck_down(sprite, position_duck, 22, -16);
}