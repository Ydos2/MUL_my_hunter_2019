/*
** EPITECH PROJECT, 2019
** duck_event
** File description:
** duck_event
*/

#include "include/frambuffer.h"
#include "include/my.h"

void analyse_events(sfRenderWindow *window, sfEvent event, duck_t *duck, ui_t *ui_struct)
{
    switch (event.type) {
    case sfEvtMouseButtonPressed:
        manage_mouse_click_start(event.mouseButton, duck, ui_struct);
        break;
    case sfEvtClosed:
        sfRenderWindow_close(window);
        break;
    default:
        break;
    }
    if (duck->health == 1)
        duck->health = 1;
    else
        duck->health = 0;
}

void manage_mouse_click_start(sfMouseButtonEvent event, duck_t *duck, ui_t *ui_struct)
{
    if (event.button == sfMouseLeft)
        manage_mouse_click_left(event, duck, ui_struct);
    else if (event.button == sfMouseRight)
        manage_mouse_click_right(event, duck, ui_struct);
}

void manage_mouse_click_left(sfMouseButtonEvent event, duck_t *duck, ui_t *ui_struct)
{
    if (ui_struct->ammo == 0) {
        sound_empty();
    } else {
        sound_fire();
        ui_struct->flash = 255;
        ui_struct->ammo -= 1; 
        if (duck->health == 1)
            duck->health = 1;
        if (event.x <= duck->pos_x_max && event.x >= duck->pos_x_min &&
        event.y <= duck->pos_y_max && event.y >= duck->pos_y_min) {
            duck->health = 1;
        } else {
            duck->is_death = 1;
            duck->health = 0;
        }
    }
}

void manage_mouse_click_right(sfMouseButtonEvent event, duck_t *duck, ui_t *ui_struct)
{
    sound_reload();
    ui_struct->ammo = 3; 
}