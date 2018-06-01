/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** ambiant sounds functions
*/

#include "runner.h"

void	sound_menu(prog_t *prog)
{
	if (prog->menu != 0) {
		sfSound_stop(prog->sound[8]);
		return;
	}
	if (sfSound_getStatus(prog->sound[8]) == sfStopped)
		sfSound_play(prog->sound[8]);
}

void	sound_game(prog_t *prog)
{
	if (prog->menu != 1) {
		sfSound_stop(prog->sound[9]);
		return;
	}
	if (sfSound_getStatus(prog->sound[9]) == sfStopped)
		sfSound_play(prog->sound[9]);
}

void	snd_char(prog_t *prog, obj_t **sprite, int i[2], int *state)
{
	if (i[0] == i[1])
		return;
	if (sprite[i[0]]->type != CHARACTER || sprite[i[1]]->type != MOB)
		return;
	if (check_collision(sprite[i[0]]->hit, sprite[i[1]]->hit)
		&& *state != 1) {
		sfSound_play(prog->sound[0]);
	}
}

void	snd_anim(prog_t *prog, obj_t **sprite, int i[2], int *state)
{
	if (i[0] == i[1])
		return;
	if (sprite[i[0]]->type != ANIM || sprite[i[1]]->type != MOB)
		return;
	if (check_collision(sprite[i[0]]->hit, sprite[i[1]]->hit)
		&& *state != 1) {
		sfSound_play(prog->sound[0]);
	}
}