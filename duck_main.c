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
    sfRenderWindow* window = NULL;
    sfSprite* sprite = NULL;
    sfTexture* texture = NULL;
    sfEvent event;
    sfClock *clock = NULL;
    duck_t *duck = NULL;
    ui_t *ui_struct = NULL;
    int help_int = 0, nbr_of_duck = 2, nbr_of_nbr_duck = nbr_of_duck;
    float seconds;

    help_int = help(ac, av);
    if (help_int == 1)
        return (0);
    ui_struct = malloc(sizeof(ui_t));
    duck = malloc(sizeof(duck_t));
    clock = sfClock_create();
    window = sfRenderWindow_create(mode, "Duck Hunt", sfResize | sfClose, NULL);
    texture = create_texture_1(texture);
    sprite = create_sprite_1(sprite, texture);
    music_game(ui_struct);
    val_start(duck, ui_struct);
    ui_struct->menu = 1, ui_struct->player_health = 0;
    Set_Spawn_Pos_1(sprite, ui_struct, duck);
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, event, duck, ui_struct);
        main_extend_1(window, ui_struct, clock);
        if (ui_struct->menu == 0) {
            main_duck(window, sprite, duck, ui_struct);
        } else
            display_ui_menu(window);
        extend_window_open(window, ui_struct, event);
    }
    destroy_obj1(sprite, window, texture, ui_struct);
    free(texture);
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
        my_putstr("\t./my_hunter\n");
        my_putstr("DESCRIPTION :\n");
        my_putstr("\tYou must kill the duck\n");
        my_putstr("\tFor fire you must use the left click on the duck\n");
        my_putstr("\tFor reload you must use the right click\n");
        my_putstr("\tIf the duck run away you lose one heart\n");
        my_putstr("\tAt 0 life you have a GAME OVER\n");
        return (1);
    } else {
        return (0);
    }
}

void main_duck(sfRenderWindow* window, sfSprite* sprite,
            duck_t *duck, ui_t *ui_struct)
{
    sfIntRect rect;
    sfVector2f position_duck;
    sfVector2f scale;

    if (duck->health == 0 && ui_struct->seconds > 0.15) {
        if (ui_struct->duck_pos_val <= 5)
            move_rect_duck(duck, 80);
        else if (ui_struct->duck_pos_val >= 6)
            move_rect_duck_flip(duck, 505);
    } else if (duck->health == 1)
        duck_die_anim(sprite, duck, ui_struct);
    if (ui_struct->player_health == 0)
        game_over(window, ui_struct);
    else {
        draw_druck(window, sprite, rect, duck);
        duck_pos(sprite, position_duck, duck);
        real_move(sprite, duck, ui_struct);
    }
    pos_life(position_duck, sprite, duck, ui_struct);
}

void real_move(sfSprite* sprite, duck_t *duck, ui_t *ui_struct)
{
    sfVector2f position_duck;

    if (duck->health == 0)
        if (ui_struct->duck_pos_val <= 5)
            move_duck_up(sprite, position_duck, 18, 0);
        else
            move_duck_down(sprite, position_duck, 18, 0);
    else
        if (ui_struct->duck_pos_val <= 5)
            move_duck_up(sprite, position_duck, 12, 11);
        else
            move_duck_down(sprite, position_duck, 12, 11);
}