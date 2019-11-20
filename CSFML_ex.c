/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** CSFML_ex
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
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

void sound_fire()
{
    sfSound *fire_sound;
    float volume = 50;
    sfSoundBuffer* buffer;

    buffer = sfSoundBuffer_createFromFile("Gun+1.wav");
    fire_sound = sfSound_create();
    sfSound_setBuffer(fire_sound, buffer);
    sfSound_setVolume(fire_sound, volume);
    sfSound_play(fire_sound);
}

void sound_empty()
{
    sfSound *empty_sound;
    float volume = 50;
    sfSoundBuffer* buffer;

    buffer = sfSoundBuffer_createFromFile("Gun+Empty.wav");
    empty_sound = sfSound_create();
    sfSound_setBuffer(empty_sound, buffer);
    sfSound_setVolume(empty_sound, volume);
    sfSound_play(empty_sound);
}

void sound_reload()
{
    sfSound *fire_sound;
    float volume = 50;
    sfSoundBuffer* buffer;

    buffer = sfSoundBuffer_createFromFile("Gun+Reload.wav");
    fire_sound = sfSound_create();
    sfSound_setBuffer(fire_sound, buffer);
    sfSound_setVolume(fire_sound, volume);
    sfSound_play(fire_sound);
}

void music_game()
{
    sfMusic *music_sound;
    float volume = 10;
    sfBool loop;

    music_sound = sfMusic_createFromFile("back-country-chase.wav");
    sfMusic_setVolume(music_sound, volume);
    sfMusic_setLoop(music_sound, loop);
    sfMusic_play(music_sound);
}

void move_rect_duck(duck_t *duck, int max_value)
{
    int i = 0;

    if (duck->offset > 90 && i == 0) {
        duck->offset = 0;
        i++;
    }
    if (duck->offset == 0 && i == 0) {
        duck->offset = 40;
        i++;
    }
    if (duck->offset == 40 && i == 0) {
        duck->offset = 80;
        i++;
    }
    if (duck->offset == 80 && i == 0)
        duck->offset = 0;
}

void move_rect_duck_die(duck_t *duck, int max_value)
{
    int i = 0;

    if (duck->offset == 230 || duck->offset == 345 && i == 0) {
        duck->offset = 275;
        i++;
    }
    if(duck->offset < 229 && i == 0) {
        duck->offset = 230;
        i++;
    }
    if (duck->offset == 275 && i == 0) {
        duck->offset = 296;
        i++;
    }
    if (duck->offset == 296 && i == 0) {
        duck->offset = 320;
        i++;
    }
    if (duck->offset == 320 && i == 0)
        duck->offset = 345;
}

sfTexture* create_texture_1(sfTexture *texture)
{
    texture = sfTexture_create(800, 800);
    texture = sfTexture_createFromFile("duck.png", NULL);
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
    ui_struct->score = 0, ui_struct->ammo = 3;
    ui_struct->ammo_pos_x = 50, ui_struct->ammo_pos_y = 500;
}

void clock_func(sfClock *clock, ui_t *ui_struct, sfTime time)
{
    time = sfClock_getElapsedTime(clock);
    ui_struct->seconds = time.microseconds / 1000000.0;
    if (ui_struct->seconds > 0.15)
        sfClock_restart(clock);
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

void create_aim(sfRenderWindow* window, sfMouseMoveEvent event)
{
    sfTexture* texture_aim;
    sfSprite* sprite_aim;
    sfVector2f position_aim;

    position_aim.x = event.x-18.5;
    position_aim.y = event.y-18.5;
    texture_aim = sfTexture_create(1920, 1080);
    texture_aim = sfTexture_createFromFile("aim.png", NULL);
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
    texture_flash = sfTexture_createFromFile("white.png", NULL);
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
    texture_bullet = sfTexture_createFromFile("ammo.png", NULL);
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

int main()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfSprite* sprite;
    sfTexture* texture;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    duck_t *duck;
    ui_t *ui_struct;

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
    Set_Spawn_Pos(window, sprite);
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event, duck, ui_struct);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        clock_func(clock, ui_struct, time);
        draw_background(window);
        draw_bullet(window, ui_struct);
        create_aim(window, event.mouseMove);
        //for (; nbr_of_duck != 0; nbr_of_duck--)
            main_duck(window, sprite, duck, ui_struct);
        //nbr_of_duck = nbr_of_nbr_duck;
        create_flash(window, ui_struct);
        sfRenderWindow_display(window);
    }
    destroy_obj1(sprite, window, texture);
    return EXIT_SUCCESS;
}

void main_duck(sfRenderWindow* window, sfSprite* sprite, duck_t *duck, ui_t *ui_struct)
{
    sfIntRect rect;
    sfVector2f position_duck;

    if (duck->health == 0) {
        if (ui_struct->seconds > 0.15)
            move_rect_duck(duck, 80);
    } else if (duck->health == 1) {
        if (ui_struct->seconds > 0.15) {
            move_rect_duck_die(duck, 365);
            duck->time_to_Death++;
        }
        if (duck->time_to_Death == 18) {
            Set_Spawn_Pos(window, sprite);
            ui_struct->score += 100;
            duck->time_to_Death = 0;
            duck->health = 0;
        }
    }
    display_ui_score_1(window);
    display_ui_score_2(window, ui_struct->score);

    draw_druck(window, sprite, rect, duck);
    duck_pos(sprite, position_duck, duck);
    if (duck->health == 0)
        move_duck(sprite, position_duck, 6, 2);
    else
        move_duck(sprite, position_duck, 0, 11);

    link_to_last_duck(duck, ui_struct);
}

int display_ui_score_1(sfRenderWindow *window)
{
    int c = 0;
    sfVector2f position_score;

    position_score.x = 1465;
    position_score.y = 865;
    if (c == 0) {
        sfFont* font;
        sfText *score;
        font = sfFont_createFromFile("krisha/Krisha-Regular.otf");
        score = sfText_create();
        sfText_setString(score, "Score :");
        sfText_setFont(score, font);
        sfText_setCharacterSize(score, 80);
        sfText_setOutlineColor(score, sfWhite);
        sfText_setOutlineThickness(score, 2);
        sfText_setPosition(score, position_score);
        sfText_setColor(score, sfBlack);
        sfRenderWindow_drawText(window, score, NULL);
        c++;
    }
}

int display_ui_score_2(sfRenderWindow *window, int score_int)
{
    int c = 0;
    sfVector2f position_score;
    char* score_char;
    score_char = my_itoa(score_int);

    position_score.x = 1620;
    position_score.y = 865;
    if (c == 0) {
        sfFont* font;
        sfText *score;
        font = sfFont_createFromFile("krisha/Krisha-Regular.otf");
        score = sfText_create();
        sfText_setString(score, score_char);
        sfText_setFont(score, font);
        sfText_setCharacterSize(score, 80);
        sfText_setOutlineColor(score, sfWhite);
        sfText_setOutlineThickness(score, 2);
        sfText_setPosition(score, position_score);
        sfText_setColor(score, sfBlack);
        sfRenderWindow_drawText(window, score, NULL);
        c++;
    }
}

char *my_itoa(int nb)
{
    char *str = malloc(sizeof(char) * 100);
    int i = 0;

    while (nb > 9) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
        i++;
    }
    str[i] = nb % 10 + 48;
    str[i + i] = '\0';
    str = my_revstr(str);
}

void destroy_obj1(sfSprite* sprite, sfRenderWindow* window, sfTexture* texture)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    //sfMusic_destroy(sfMusic* music);
}

void duck_pos(sfSprite* sprite, sfVector2f position_duck, duck_t *duck)
{
    position_duck = sfSprite_getPosition(sprite);
    duck->pos_x_max = position_duck.x+140;
    duck->pos_x_min = position_duck.x;
    duck->pos_y_max = position_duck.y+110;
    duck->pos_y_min = position_duck.y;
}

void move_duck(sfSprite* sprite, sfVector2f position_duck, int speed_x, int speed_y)
{
    position_duck.y = speed_y;
    if (position_duck.x == 800)
        position_duck.x = 0;
    else
        position_duck.x += speed_x;
    sfSprite_move(sprite, position_duck);
}

void draw_background(sfRenderWindow* window)
{
    sfTexture* texture_background;
    sfSprite* sprite_background;
    sfVector2f scale;

    scale.x = 7.6;
    scale.y = 4.25;
    texture_background = sfTexture_create(1920, 1080);
    texture_background = sfTexture_createFromFile("background.png", NULL);
    sprite_background = sfSprite_create();
    sfSprite_setTexture(sprite_background, texture_background, sfTrue);
    sfSprite_setScale(sprite_background, scale);
    sfRenderWindow_drawSprite(window, sprite_background, NULL);
}

void draw_druck(sfRenderWindow* window, sfSprite* sprite, sfIntRect rect, duck_t *duck)
{
    sfVector2f scale;

    if (duck->is_death == 1) {
        duck->is_death = 0;
    }
    if (duck->offset > 231) {
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

void Set_Spawn_Pos(sfRenderWindow* window, sfSprite* sprite)
{
    sfVector2f duck_pos;

    duck_pos.x = -300;
    duck_pos.y = -300;
    sfSprite_setPosition(sprite, duck_pos);
}