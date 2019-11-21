/*
** EPITECH PROJECT, 2019
** duck_main
** File description:
** duck_main
*/

#include "include/frambuffer.h"
#include "include/my.h"

int main(int ac, char **av)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfSprite* sprite;
    sfTexture* texture;
    sfEvent event;
    sfClock *clock;
    duck_t *duck;
    ui_t *ui_struct;
    int help_int = 0;

    help_int = help(ac, av);
    if (help_int == 1)
        return (0);
    int nbr_of_duck = 2, nbr_of_nbr_duck = nbr_of_duck;
    ui_struct = malloc(sizeof(ui_t));
    duck = malloc(sizeof(duck_t));
    float seconds;
    clock = sfClock_create();
    window = sfRenderWindow_create(mode, "Duck Hunt", sfResize | sfClose, NULL);
    texture = create_texture_1(texture);
    sprite = create_sprite_1(sprite, texture);
    if (!(window || texture))
        return EXIT_FAILURE;
    music_game();
    val_start(duck, ui_struct);
    Set_Spawn_Pos(window, sprite, ui_struct);
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event, duck, ui_struct);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        clock_func(clock, ui_struct);
        draw_background_up(window);
        //for (; nbr_of_duck != 0; nbr_of_duck--)
            main_duck(window, sprite, duck, ui_struct);
        //nbr_of_duck = nbr_of_nbr_duck;
        extend_window_open(window, ui_struct, event);
    }
    destroy_obj1(sprite, window, texture);
    return EXIT_SUCCESS;
}

void extend_window_open(sfRenderWindow *window, ui_t *ui_struct, sfEvent event)
{
    draw_background_down(window);
    display_ui_score_1(window);
    display_ui_score_2(window, ui_struct);
    display_ui_mult_score_1(window);
    display_ui_mult_score_2(window, ui_struct);
    draw_bullet(window, ui_struct);
    draw_health(window, ui_struct);
    create_aim(window, event.mouseMove);
    create_flash(window, ui_struct);
    sfRenderWindow_display(window);
}

int help(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE :\n");
        my_putstr("    ./my_hunter\n");
        my_putstr("DESCRIPTION :\n");
        my_putstr("    You must kill the duck\n");
        my_putstr("    For fire you must use the left click on the duck\n");
        my_putstr("    For reload you must use the right click\n");
        my_putstr("    If the duck run away you lose one heart\n");
        my_putstr("    At 0 life you have a GAME OVER\n");
        return (1);
    } else {
        return (0);
    }
}

void main_duck(sfRenderWindow* window, sfSprite* sprite, duck_t *duck, ui_t *ui_struct)
{
    sfIntRect rect;
    sfVector2f position_duck;
    sfVector2f scale;

    if (duck->health == 0 && ui_struct->seconds > 0.15) {
        if (ui_struct->duck_pos_val <= 5)
            move_rect_duck(duck, 80);
        else if (ui_struct->duck_pos_val >= 6)
            move_rect_duck_flip(duck, 505);
    } else if (duck->health == 1) {
        if (ui_struct->seconds > 0.15) {
            move_rect_duck_die(duck, 365);
            duck->time_to_Death++;
        }
        if (duck->time_to_Death == 18) {
            Set_Spawn_Pos(window, sprite, ui_struct);
            duck->time_to_Death = 0;
            duck->health = 0;
        }
    }

    draw_druck(window, sprite, rect, duck);
    duck_pos(sprite, position_duck, duck);
    if (duck->health == 0)
        if (ui_struct->duck_pos_val <= 5)
            move_duck_up(sprite, position_duck, 6, 0);
        else
            move_duck_down(sprite, position_duck, 24, 0);
    else
        if (ui_struct->duck_pos_val <= 5)
            move_duck_up(sprite, position_duck, 0, 11);
        else
            move_duck_down(sprite, position_duck, 18, 11);

    link_to_last_duck(duck, ui_struct);
}

void link_to_last_duck(duck_t *new_duck, ui_t *ui_struct)
{
    duck_t *duck = ui_struct->duck_list;

    if (duck == NULL) {
        ui_struct->duck_list = new_duck;
        new_duck->next = NULL;
        return;
    }
    for (; duck->next != NULL; duck = duck->next);
    duck->next = new_duck;
    new_duck->next = NULL;
}