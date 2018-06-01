/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** keys for rog character
*/

#include "runner.h"

void	rog_key_move(prog_t *prog, obj_t **sprite)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) && prog->state.rog[0] == 0) {
		sfSound_play(prog->sound[5]);
		prog->state.rog[0] = 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown) && prog->state.rog[0] == 0) {
		sfSound_play(prog->sound[12]);
		sprite[11]->pos = sfSprite_getPosition(sprite[10]->obj);
		prog->state.rog[0] = 2;
	}
}

void	rog_key_spell(prog_t *prog, obj_t **sprite)
{
	if (sfKeyboard_isKeyPressed(sfKeyW) && prog->state.rog[0] != 2 &&
	prog->state.rog[2] == 0) {
		sfSound_play(prog->sound[12]);
		prog->state.rog[2] = 1;
		sfSprite_move(sprite[10]->obj, (sfVector2f) {0, -60});
	}
	if (sfKeyboard_isKeyPressed(sfKeyX) && prog->state.rog[0] != 2 &&
	prog->state.rog[1] == 0) {
		sfSound_play(prog->sound[12]);
		prog->state.rog[1] = (rand() % 2) + 1;
		sfSprite_move(sprite[10]->obj, (sfVector2f) {0, -30});
	}
	if (sfKeyboard_isKeyPressed(sfKeyC) && prog->state.rog[0] != 2 &&
	prog->state.rog[1] == 0 && prog->state.rog[2] == 0 &&
	prog->state.rog[3] == 0) {
		prog->state.rog[3] = 1;
		rog_heal(sprite[10]);
	}
}