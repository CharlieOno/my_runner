/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** event handling functions
*/

#include "runner.h"

void	hex_key_move(prog_t *prog)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) && prog->state.hex[0] == 0) {
		sfSound_play(prog->sound[5]);
		prog->state.hex[0] = 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown) && prog->state.hex[0] == 0)
		prog->state.hex[0] = 2;
}

void	hex_key_spell(prog_t *prog, obj_t **sprite)
{
	if (sfKeyboard_isKeyPressed(sfKeyX) && prog->state.hex[0] != 2) {
		sprite[4]->pos = sfSprite_getPosition(sprite[3]->obj);
		prog->state.hex[1] = 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyW) && prog->state.hex[0] != 2) {
		sprite[5]->pos = sfSprite_getPosition(sprite[3]->obj);
		prog->state.hex[2] = 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyC) && prog->state.hex[0] != 2) {
		sprite[6]->pos = sfSprite_getPosition(sprite[3]->obj);
		prog->state.hex[3] = 1;
	}
}

void	mitty_key_move(prog_t *prog)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) && prog->state.mitty[0] == 0) {
		sfSound_play(prog->sound[5]);
		prog->state.mitty[0] = 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown) && prog->state.mitty[0] == 0)
		prog->state.mitty[0] = 2;
}

void	mitty_key_spell(prog_t *prog, obj_t **sprite)
{
	if (sfKeyboard_isKeyPressed(sfKeyX) && prog->state.mitty[0] != 2) {
		sprite[8]->pos = sfSprite_getPosition(sprite[7]->obj);
		sprite[8]->pos.y += 20;
		prog->state.mitty[1] = 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyW) && prog->state.mitty[0] != 2
		&& prog->state.mitty[0] != 1) {
		sprite[9]->pos = sfSprite_getPosition(sprite[7]->obj);
		sprite[9]->pos.y += 70;
		prog->state.mitty[2] = 1;
	}
}

void	key_character(prog_t *prog, obj_t **sprite)
{
	if (prog->charac == 0) {
		hex_key_move(prog);
		hex_key_spell(prog, sprite);
	}
	if (prog->charac == 1) {
		mitty_key_move(prog);
		mitty_key_spell(prog, sprite);
	}
	if (prog->charac == 2) {
		rog_key_move(prog, sprite);
		rog_key_spell(prog, sprite);
	}
}