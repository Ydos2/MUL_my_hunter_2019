/*
** EPITECH PROJECT, 2019
** duck_draw
** File description:
** duck_draw_1
*/

#include "include/frambuffer.h"
#include "include/my.h"

void create_aim(sfRenderWindow* window, sfMouseMoveEvent event)
{
    sfTexture* texture_aim;
    sfSprite* sprite_aim;
    sfVector2f position_aim;

    position_aim.x = event.x-18.5;
    position_aim.y = event.y-18.5;
    texture_aim = sfTexture_create(1920, 1080);
    texture_aim = sfTexture_createFromFile("./texture/aim.png", NULL);
    sprite_aim = sfSprite_create();
    sfSprite_setTexture(sprite_aim, texture_aim, sfTrue);
    sfSprite_setPosition(sprite_aim, position_aim);
    position_aim.x = 0;
    position_aim.y = 0;
    sfRenderWindow_drawSprite(window, sprite_aim, NULL);
}

void create_flash(sfRenderWindow* window, ui_t *ui_struct)
{
    sfTexture* texture_flash;
    sfSprite* sprite_flash;
    sfColor color;
    sfVector2f scale;

    scale.x = 9;
    scale.y = 4.5;
    color.r = 255;
    color.g = 255;
    color.b = 255;
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

void draw_bullet(sfRenderWindow* window, ui_t *ui_struct)
{
    sfTexture* texture_bullet;
    sfSprite* sprite_bullet;
    sfVector2f position_bullet;
    sfVector2f scale;

    scale.x = 3.5;
    scale.y = 3.5;
    texture_bullet = sfTexture_create(800, 800);
    texture_bullet = sfTexture_createFromFile("./texture/ammo.png", NULL);
    sprite_bullet = sfSprite_create();
    sfSprite_setScale(sprite_bullet, scale);
    position_bullet.x = 185;
    position_bullet.y = 880;
    sfSprite_setTexture(sprite_bullet, texture_bullet, sfTrue);
    draw_bullet_2(window, ui_struct, sprite_bullet, position_bullet);
    position_bullet.x = 0;
    position_bullet.y = 0;
}

void draw_bullet_2(sfRenderWindow* window, ui_t *ui_struct, sfSprite* sprite_bullet, sfVector2f position_bullet)
{
    if (ui_struct->ammo >= 1) {
        sfSprite_setPosition(sprite_bullet, position_bullet);
        sfRenderWindow_drawSprite(window, sprite_bullet, NULL);
    }
    if (ui_struct->ammo >= 2) {
        position_bullet.x = 245;
        position_bullet.y = 880;
        sfSprite_setPosition(sprite_bullet, position_bullet);
        sfRenderWindow_drawSprite(window, sprite_bullet, NULL);
    }
    if (ui_struct->ammo >= 3) {
        position_bullet.x = 305;
        position_bullet.y = 880;
        sfSprite_setPosition(sprite_bullet, position_bullet);
        sfRenderWindow_drawSprite(window, sprite_bullet, NULL);
    }
}

void draw_health(sfRenderWindow* window, ui_t *ui_struct)
{
    sfTexture* texture_health;
    sfSprite* sprite_health;
    sfVector2f position_health;
    sfVector2f scale;

    scale.x = 0.425;
    scale.y = 0.425;
    texture_health = sfTexture_create(800, 800);
    texture_health = sfTexture_createFromFile("./texture/heart.png", NULL);
    sprite_health = sfSprite_create();
    sfSprite_setScale(sprite_health, scale);
    position_health.x = 1040;
    position_health.y = 877;
    sfSprite_setTexture(sprite_health, texture_health, sfTrue);
    draw_health_2(window, ui_struct, sprite_health, position_health);
    position_health.x = 0;
    position_health.y = 0;
}

void draw_health_2(sfRenderWindow* window, ui_t *ui_struct, sfSprite* sprite_health, sfVector2f position_health)
{
    if (ui_struct->player_health >= 1) {
        sfSprite_setPosition(sprite_health, position_health);
        sfRenderWindow_drawSprite(window, sprite_health, NULL);
    }
    if (ui_struct->player_health >= 2) {
        position_health.x = 1140;
        position_health.y = 877;
        sfSprite_setPosition(sprite_health, position_health);
        sfRenderWindow_drawSprite(window, sprite_health, NULL);
    }
    if (ui_struct->player_health >= 3) {
        position_health.x = 1240;
        position_health.y = 877;
        sfSprite_setPosition(sprite_health, position_health);
        sfRenderWindow_drawSprite(window, sprite_health, NULL);
    }
}