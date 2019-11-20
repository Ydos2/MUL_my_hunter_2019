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
    sfTexture* texture_background;
    sfSprite* sprite_background;
    sfVector2f scale;

    scale.x = 7.6;
    scale.y = 4.25;
    texture_background = sfTexture_create(1920, 1080);
    texture_background = sfTexture_createFromFile("./texture/background_up.png", NULL);
    sprite_background = sfSprite_create();
    sfSprite_setTexture(sprite_background, texture_background, sfTrue);
    sfSprite_setScale(sprite_background, scale);
    sfRenderWindow_drawSprite(window, sprite_background, NULL);
}

void draw_background_down(sfRenderWindow* window)
{
    sfTexture* texture_background;
    sfSprite* sprite_background;
    sfVector2f scale;

    scale.x = 7.6;
    scale.y = 4.25;
    texture_background = sfTexture_create(1920, 1080);
    texture_background = sfTexture_createFromFile("./texture/background_down.png", NULL);
    sprite_background = sfSprite_create();
    sfSprite_setTexture(sprite_background, texture_background, sfTrue);
    sfSprite_setScale(sprite_background, scale);
    sfRenderWindow_drawSprite(window, sprite_background, NULL);
}