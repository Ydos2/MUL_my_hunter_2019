/*
** EPITECH PROJECT, 2019
** duck_sound
** File description:
** duck_sound
*/

#include "include/frambuffer.h"
#include "include/my.h"

void sound_fire(void)
{
    sfSound *fire_sound = NULL;
    float volume = 50;
    sfSoundBuffer* buffer = NULL;

    buffer = sfSoundBuffer_createFromFile("./sound/Gun+1.ogg");
    fire_sound = sfSound_create();
    sfSound_setBuffer(fire_sound, buffer);
    sfSound_setVolume(fire_sound, volume);
    sfSound_play(fire_sound);
}

void sound_empty(void)
{
    sfSound *empty_sound = NULL;
    float volume = 50;
    sfSoundBuffer* buffer = NULL;

    buffer = sfSoundBuffer_createFromFile("./sound/Gun+Empty.ogg");
    empty_sound = sfSound_create();
    sfSound_setBuffer(empty_sound, buffer);
    sfSound_setVolume(empty_sound, volume);
    sfSound_play(empty_sound);
}

void sound_reload(void)
{
    sfSound *fire_sound = NULL;
    float volume = 50;
    sfSoundBuffer* buffer = NULL;

    buffer = sfSoundBuffer_createFromFile("./sound/Gun+Reload.ogg");
    fire_sound = sfSound_create();
    sfSound_setBuffer(fire_sound, buffer);
    sfSound_setVolume(fire_sound, volume);
    sfSound_play(fire_sound);
}

void music_game(ui_t *ui_struct)
{
    float volume = 10;
    sfBool loop = sfTrue;

    ui_struct->music_sound = sfMusic_createFromFile("./sound/country.ogg");
    sfMusic_setVolume(ui_struct->music_sound, volume);
    sfMusic_setLoop(ui_struct->music_sound, loop);
    sfMusic_play(ui_struct->music_sound);
}