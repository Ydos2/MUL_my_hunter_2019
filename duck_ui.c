/*
** EPITECH PROJECT, 2019
** duck_ui
** File description:
** duck_ui
*/

#include "include/frambuffer.h"
#include "include/my.h"

void display_ui_score_1(sfRenderWindow *window)
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

void display_ui_score_2(sfRenderWindow *window, ui_t *ui_struct)
{
    int c = 0;
    sfVector2f position_score;
    char* score_char;
    score_char = my_itoa(ui_struct->score);

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

void display_ui_mult_score_1(sfRenderWindow *window)
{
    int c = 0;
    sfVector2f position_score;

    position_score.x = 480;
    position_score.y = 865;
    if (c == 0) {
        sfFont* font;
        sfText *score;
        font = sfFont_createFromFile("krisha/Krisha-Regular.otf");
        score = sfText_create();
        sfText_setString(score, "Combo : +");
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

void display_ui_mult_score_2(sfRenderWindow *window, ui_t *ui_struct)
{
    int c = 0;
    sfVector2f position_score;
    char* score_char;
    score_char = my_itoa(ui_struct->scrore_mult);

    position_score.x = 685;
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