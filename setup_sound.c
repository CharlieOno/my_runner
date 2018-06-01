/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** setup sounds functions
*/

#include "runner.h"

sfSound	*create_sound(char *path, int loop)
{
	sfSound 	*sound = sfSound_create();
	sfSoundBuffer 	*buffer = sfSoundBuffer_createFromFile(path);

	sfSound_setBuffer(sound, buffer);
	if (loop)
		sfSound_setLoop(sound, sfTrue);
	else
		sfSound_setLoop(sound, sfFalse);
	return (sound);
}

void	setup_general_sounds(prog_t *prog)
{
	prog->sound = malloc(sizeof(sfSound*) * NB_SOUND);

	prog->sound[0] = create_sound("snd/hit.wav", 0);
	prog->sound[1] = create_sound("snd/pausein.wav", 0);
	prog->sound[2] = create_sound("snd/pauseout.wav", 0);
	prog->sound[3] = create_sound("snd/menu.wav", 0);
	prog->sound[4] = create_sound("snd/dead.wav", 0);
	prog->sound[5] = create_sound("snd/jump.wav", 0);
	prog->sound[6] = create_sound("snd/up.wav", 0);
	prog->sound[7] = create_sound("snd/cast.wav", 0);
	prog->sound[8] = create_sound("snd/lofi.wav", 1);
	prog->sound[9] = create_sound("snd/battle.wav", 1);
	prog->sound[10] = create_sound("snd/win.wav", 0);
	prog->sound[11] = create_sound("snd/level.wav", 0);
}

void	setup_spell_sounds(prog_t *prog)
{
	prog->sound[12] = create_sound("snd/sword.wav", 0);
	prog->sound[13] = create_sound("snd/roar.wav", 0);
	prog->sound[14] = create_sound("snd/whoop.wav", 0);
	prog->sound[15] = create_sound("snd/fireball.wav", 0);
	prog->sound[16] = create_sound("snd/bubble.wav", 0);
	prog->sound[17] = create_sound("snd/charge.wav", 0);
	prog->sound[18] = create_sound("snd/hand.wav", 0);
}