/*
** EPITECH PROJECT, 2019
** duck_sound_ui
** File description:
** duck_sound_ui
*/

#include "include/frambuffer.h"
#include "include/my.h"

void sound_start(void)
{
    sfSound *fire_sound = NULL;
    float volume = 50;
    sfSoundBuffer* buffer = NULL;

    buffer = sfSoundBuffer_createFromFile("./sound/start_sound.ogg");
    fire_sound = sfSound_create();
    sfSound_setBuffer(fire_sound, buffer);
    sfSound_setVolume(fire_sound, volume);
    sfSound_play(fire_sound);
}

void sound_die(void)
{
    sfSound *empty_sound = NULL;
    float volume = 50;
    sfSoundBuffer* buffer = NULL;

    buffer = sfSoundBuffer_createFromFile("./sound/game_over.ogg");
    empty_sound = sfSound_create();
    sfSound_setBuffer(empty_sound, buffer);
    sfSound_setVolume(empty_sound, volume);
    sfSound_play(empty_sound);
}