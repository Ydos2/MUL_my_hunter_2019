/*
** EPITECH PROJECT, 2019
** ui_menu
** File description:
** ui_menu
*/

#include "include/frambuffer.h"
#include "include/my.h"

void game_over(sfRenderWindow *window, ui_t *ui_struct)
{
    display_ui_gameover(window);
}

void menu(sfRenderWindow *window, ui_t *ui_struct)
{
    display_ui_menu(window);
}

void display_ui_menu(sfRenderWindow *window)
{
    int c = 0;
    sfVector2f position_score;

    position_score.x = 650;
    position_score.y = 350;
    sfFont* font = NULL;
    sfText *score = NULL;
    font = sfFont_createFromFile("krisha/Krisha-Regular.otf");
    score = sfText_create();
    sfText_setString(score, "Start to HUNT!");
    sfText_setFont(score, font);
    sfText_setCharacterSize(score, 200);
    sfText_setOutlineColor(score, sfWhite);
    sfText_setOutlineThickness(score, 2);
    sfText_setPosition(score, position_score);
    sfText_setColor(score, sfBlack);
    sfRenderWindow_drawText(window, score, NULL);
    free(font);
}