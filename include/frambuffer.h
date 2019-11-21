/*
** EPITECH PROJECT, 2019
** frambuffer_h
** File description:
** frambuffer
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Export.h>
#include <stdlib.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Graphics/FontInfo.h>
#include <SFML/Graphics/Glyph.h>
#include <SFML/Graphics/Types.h>
#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    unsigned char *pixels;
} framebuffer_t;

typedef struct duck {
    int health;
    int pos_x_min;
    int pos_x_max;
    int pos_y_min;
    int pos_y_max;
    int offset;
    int spawn;
    int time_to_Death;
    int is_death;
    struct duck *next;
} duck_t;

typedef struct ui {
    int player_health;
    int ammo;
    int ammo_pos_x;
    int ammo_pos_y;
    int score;
    int round;
    int duck_pos_val;
    float seconds;
    int flash;
    int scrore_mult;
    sfTime time;
    struct duck *duck_list;
} ui_t;

void move_rect_duck_flip(duck_t *duck, int max_value);
void draw_health(sfRenderWindow* window, ui_t *ui_struct);
void draw_health_2(sfRenderWindow* window, ui_t *ui_struct, sfSprite* sprite_bullet, sfVector2f position_bullet);
void extend_window_open(sfRenderWindow *window, ui_t *ui_struct, sfEvent event);
int help(int ac, char **av);
void display_ui_mult_score_1(sfRenderWindow *window);
void display_ui_mult_score_2(sfRenderWindow *window, ui_t *ui_struct);
void create_flash(sfRenderWindow* window, ui_t *ui_struct);
void Set_Spawn_Pos(sfRenderWindow* window, sfSprite* sprite, ui_t *ui_struct);
void manage_mouse_click_start(sfMouseButtonEvent event, duck_t *duck, ui_t *ui_struct);
void draw_bullet(sfRenderWindow* window, ui_t *ui_struct);
void draw_bullet_2(sfRenderWindow* window, ui_t *ui_struct, sfSprite* sprite_bullet, sfVector2f position_bullet);
void create_aim(sfRenderWindow* window, sfMouseMoveEvent event);
void link_to_last_duck(duck_t *new_duck, ui_t *ui_struct);
void main_duck2(sfRenderWindow* window, sfSprite* sprite, duck_t *duck, ui_t *ui_struct);
void clock_func(sfClock *clock, ui_t *ui_struct);
void val_start(duck_t *duck, ui_t *ui_struct);
sfTexture* create_texture_1(sfTexture *texture);
sfSprite* create_sprite_1(sfSprite *sprite, sfTexture* texture);
void main_duck(sfRenderWindow* window, sfSprite* sprite, duck_t *duck, ui_t *ui_struct);
void draw_background_up(sfRenderWindow* window);
void draw_background_down(sfRenderWindow* window);
void display_ui_score_1(sfRenderWindow *window);
void display_ui_score_2(sfRenderWindow *window, ui_t *ui_struct);
void destroy_obj1(sfSprite* sprite, sfRenderWindow* window, sfTexture* texture);
void sound_fire();
void sound_empty();
void sound_reload();
void music_game();
void move_rect_duck(duck_t *duck, int max_value);
void move_rect_duck_die(duck_t *duck, int max_value);
void duck_pos(sfSprite* sprite, sfVector2f position_duck, duck_t *duck);
void draw_druck(sfRenderWindow* window, sfSprite* sprite, sfIntRect rect, duck_t *duck);
void move_duck_up(sfSprite* sprite, sfVector2f position_duck, int speed_x, int speed_y);
void move_duck_down(sfSprite* sprite, sfVector2f position_duck, int speed_x, int speed_y);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void analyse_events(sfRenderWindow *window, sfEvent event, duck_t *duck, ui_t *ui_struct);
void manage_mouse_click_left(sfMouseButtonEvent event, duck_t *duck, ui_t *ui_struct);
void manage_mouse_click_right(sfMouseButtonEvent event, duck_t *duck, ui_t *ui_struct);
#endif /*FRAMBUFFER_H_ */