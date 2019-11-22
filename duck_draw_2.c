/*
** EPITECH PROJECT, 2019
** duck_draw_2
** File description:
** duck_draw_2
*/

#include "include/frambuffer.h"
#include "include/my.h"

void draw_background_up(sfRenderWindow* window)
{
    sfTexture* texture_background = NULL;
    sfSprite* sprite_background = NULL;
    sfVector2f scale;

    scale.x = 7.6;
    scale.y = 4.25;
    texture_background = sfTexture_create(1920, 1080);
    texture_background = sfTexture_createFromFile("./texture/bg_u.png", NULL);
    sprite_background = sfSprite_create();
    sfSprite_setTexture(sprite_background, texture_background, sfTrue);
    sfSprite_setScale(sprite_background, scale);
    sfRenderWindow_drawSprite(window, sprite_background, NULL);
}

void draw_background_down(sfRenderWindow* window)
{
    sfTexture* texture_background = NULL;
    sfSprite* sprite_background = NULL;
    sfVector2f scale;

    scale.x = 7.6;
    scale.y = 4.25;
    texture_background = sfTexture_create(1920, 1080);
    texture_background = sfTexture_createFromFile("./texture/bg_d.png", NULL);
    sprite_background = sfSprite_create();
    sfSprite_setTexture(sprite_background, texture_background, sfTrue);
    sfSprite_setScale(sprite_background, scale);
    sfRenderWindow_drawSprite(window, sprite_background, NULL);
}

void create_flash(sfRenderWindow* window, ui_t *ui_struct)
{
    sfTexture* texture_flash = NULL;
    sfSprite* sprite_flash = NULL;
    sfColor color;
    sfVector2f scale;

    scale.x = 9, scale.y = 4.5;
    color.r = 255, color.g = 255, color.b = 255;
    color.a = ui_struct->flash;
    if (ui_struct->flash > 0)
        ui_struct->flash -= 17;
    else if (ui_struct->flash < 0)
        ui_struct->flash = 0;
    texture_flash = sfTexture_create(1920, 1080);
    texture_flash = sfTexture_createFromFile("./texture/white.png", NULL);
    sprite_flash = sfSprite_create();
    sfSprite_setTexture(sprite_flash, texture_flash, sfTrue);
    sfSprite_setScale(sprite_flash, scale);
    sfSprite_setColor(sprite_flash, color);
    sfRenderWindow_drawSprite(window, sprite_flash, NULL);
}