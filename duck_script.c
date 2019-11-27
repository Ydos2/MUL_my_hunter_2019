/*
** EPITECH PROJECT, 2019
** duck_script
** File description:
** duck_script
*/

#include "include/frambuffer.h"
#include "include/my.h"

void set_duck_pos(sfSprite* sprite, sfVector2f position_duck, duck_t *duck)
{
    position_duck = sfSprite_getPosition(sprite);
    duck->pos_x_max = position_duck.x+140;
    duck->pos_x_min = position_duck.x;
    duck->pos_y_max = position_duck.y+110;
    duck->pos_y_min = position_duck.y;
}

void move_duck_up(sfSprite* sprite, sfVector2f position_duck,
                int speed_x, int speed_y)
{
    position_duck.x = 0;
    position_duck.y = speed_y;
    if (position_duck.x == 800)
        position_duck.x = 0;
    else
        position_duck.x += speed_x;
    sfSprite_move(sprite, position_duck);
}

void move_duck_down(sfSprite* sprite, sfVector2f position_duck,
                    int speed_x, int speed_y)
{
    position_duck.x = 0;
    position_duck.y = speed_y;
    if (position_duck.x == 800)
        position_duck.x = 0;
    else
        position_duck.x -= speed_x;
    sfSprite_move(sprite, position_duck);
}

void draw_druck(sfRenderWindow* window, sfSprite* sprite,
                sfIntRect rect, duck_t *duck)
{
    sfVector2f scale;

    if (duck->is_death == 1) {
        duck->is_death = 0;
    }
    if (duck->offset > 231 && duck->offset < 424) {
        rect.width = 20;
        rect.height = 40;
    } else {
        rect.width = 40;
        rect.height = 40;
    }
    scale.x = 3.5;
    scale.y = 3.5;
    rect.top = 0;
    rect.left = duck->offset;
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_setTextureRect(sprite, rect);
}