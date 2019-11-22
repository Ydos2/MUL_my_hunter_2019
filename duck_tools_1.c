/*
** EPITECH PROJECT, 2019
** duck_tools_1
** File description:
** duck_tools_1
*/

#include "include/frambuffer.h"
#include "include/my.h"

sfTexture* create_texture_1(sfTexture *texture)
{
    texture = sfTexture_create(800, 800);
    texture = sfTexture_createFromFile("./texture/duck.png", NULL);
    return (texture);
}

sfSprite* create_sprite_1(sfSprite *sprite, sfTexture* texture)
{
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

void val_start(duck_t *duck, ui_t *ui_struct)
{
    duck->health = 0, duck->offset = 0;
    ui_struct->score = 0, ui_struct->ammo = 3, ui_struct->scrore_mult = 0;
    ui_struct->ammo_pos_x = 50, ui_struct->ammo_pos_y = 500;
    ui_struct->player_health = 3;
    ui_struct->flash = 255;
    duck->is_death = 0;
}

void clock_func(ui_t *ui_struct)
{
    ui_struct->time = sfClock_getElapsedTime(ui_struct->clock);
    ui_struct->seconds = ui_struct->time.microseconds / 1000000.0;
    if (ui_struct->seconds > 0.15)
        sfClock_restart(ui_struct->clock);
}

void destroy_obj1(ui_t *ui)
{
    sfMusic_stop(ui->music_sound);
    sfMusic_destroy(ui->music_sound);
    sfClock_destroy(ui->clock);
    sfSprite_destroy(ui->sprite);
    sfTexture_destroy(ui->texture);
    sfRenderWindow_destroy(ui->window);
}