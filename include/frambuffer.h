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
    int duck_pos_win;
} duck_t;

typedef struct ui {
    int menu;
    int button_start;
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
    int sound_die;
    sfSprite* sprite;
    sfTexture* texture;
    sfTime time;
    sfClock *clock;
    sfMusic *music_sound;
    sfRenderWindow* window;
} ui_t;

void move_ai_up(sfSprite* sprite, duck_t *duck, ui_t *ui_struct);
void move_ai_down(sfSprite* sprite, duck_t *duck, ui_t *ui_struct);
void sound_start(void);
void sound_die(void);
void main_extend_2(ui_t *ui_struct, duck_t *duck);
void main_extend_1(sfRenderWindow *window, ui_t *ui_struct);
void duck_die_anim(sfSprite* sprite,
            duck_t *duck, ui_t *ui_struct);
void pos_life(sfVector2f position_duck, sfSprite* sprite,
            duck_t *duck, ui_t *ui_struct);
void analyse_events(sfRenderWindow *window, sfEvent event,
                    duck_t *duck, ui_t *ui_struct);
void display_ui_menu(sfRenderWindow *window);
void manage_mouse_click_gameover(sfMouseButtonEvent event,
                                duck_t *duck, ui_t *ui_struct);
void real_move(sfSprite* sprite, duck_t *duck, ui_t *ui_struct);
void display_ui_gameover(sfRenderWindow *window);
void menu(sfRenderWindow *window, ui_t *ui_struct);
void game_over(sfRenderWindow *window, ui_t *ui_struct);
void move_rect_duck_flip(duck_t *duck, int max_value);
void draw_health(sfRenderWindow* window, ui_t *ui_struct);
void draw_health_2(sfRenderWindow* window, ui_t *ui_struct,
                sfSprite* sprite_health, sfVector2f position_health);
void extend_window_open(sfRenderWindow *window, ui_t *ui_struct, sfEvent event);
int help(int ac, char **av);
void display_ui_mult_score_1(sfRenderWindow *window);
void display_ui_mult_score_2(sfRenderWindow *window, ui_t *ui_struct);
void create_flash(sfRenderWindow* window, ui_t *ui_struct);
void Set_Spawn_Pos_1(sfSprite* sprite, ui_t *ui_struct, duck_t *duck);
void Set_Spawn_Pos_2(int x, sfSprite* sprite, duck_t *duck,
                    sfVector2f duck_pos);
void Set_Spawn_Pos_3(int x, sfSprite* sprite, duck_t *duck,
                    sfVector2f duck_pos);
void manage_mouse_click_start(sfMouseButtonEvent event,
                            duck_t *duck, ui_t *ui_struct);
void draw_bullet(sfRenderWindow* window, ui_t *ui_struct);
void draw_bullet_2(sfRenderWindow* window, ui_t *ui_struct,
                sfSprite* sprite_bullet, sfVector2f position_bullet);
void create_aim(sfRenderWindow* window, sfMouseMoveEvent event);
void clock_func(ui_t *ui_struct);
void val_start(duck_t *duck, ui_t *ui_struct);
sfTexture* create_texture_1(sfTexture *texture);
sfSprite* create_sprite_1(sfSprite *sprite, sfTexture* texture);
void main_duck(sfRenderWindow* window, sfSprite* sprite,
            duck_t *duck, ui_t *ui_struct);
void draw_background_up(sfRenderWindow* window);
void draw_background_down(sfRenderWindow* window);
void display_ui_score_1(sfRenderWindow *window);
void display_ui_score_2(sfRenderWindow *window, ui_t *ui_struct);
void destroy_obj1(ui_t *ui);
void sound_fire(void);
void sound_empty(void);
void sound_reload(void);
void music_game(ui_t *ui_struct);
void move_rect_duck(duck_t *duck, int max_value);
void move_rect_duck_die(duck_t *duck, int max_value);
void duck_pos(sfSprite* sprite, sfVector2f position_duck, duck_t *duck);
void draw_druck(sfRenderWindow* window, sfSprite* sprite,
                sfIntRect rect, duck_t *duck);
void move_duck_up(sfSprite* sprite, sfVector2f position_duck,
                int speed_x, int speed_y);
void move_duck_down(sfSprite* sprite, sfVector2f position_duck,
                    int speed_x, int speed_y);
void manage_mouse_click_gameover(sfMouseButtonEvent event,
                                duck_t *duck, ui_t *ui_struct);
void manage_mouse_click_left(sfMouseButtonEvent event, duck_t *duck,
                            ui_t *ui_struct);
void manage_mouse_click_right(sfMouseButtonEvent event, duck_t *duck,
                            ui_t *ui_struct);
#endif /*FRAMBUFFER_H_ */