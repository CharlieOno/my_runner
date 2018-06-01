/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** parsing functions for .map file
*/

#include "runner.h"

void	engine_end(obj_t **sprite, prog_t *prog, int **index)
{
	int 	charac_id = 3;

	if (prog->map[**index] != 'e')
		return;
	prog->state.win = 1;
	charac_id = (prog->charac == 1) ? 7 : charac_id;
	charac_id = (prog->charac == 2) ? 10 : charac_id;
	sfSound_play(prog->sound[10]);
	save_stats(sprite[3], "data/hex.dat");
	save_stats(sprite[7], "data/mitty.dat");
	save_stats(sprite[10], "data/rog.dat");
	prog->menu = 3;
}

void	engine_spawn(obj_t **sprite, prog_t *prog, int **index)
{
	int	state = 0;

	if (prog->map[**index] != 's')
		return;
	**index += 2;
	prog->state.mob[my_getnbr(prog->map + **index)] = 1;
	state = my_getnbr(prog->map + **index);
	**index += 4;
	generate_mob_stats(sprite, state, my_getnbr(prog->map + **index));
	**index += 3;
	prog->delay = my_getnbr(prog->map + **index);
	**index += 6;
}

void	engine_text(prog_t *prog, int **index)
{
	if (prog->map[**index] != 't')
		return;
	**index += 3;
	prog->delay = 1;
	for (int i = 0; i < 255; i++)
		prog->text[i] = 0;
	for (int i = 0; prog->map[**index] != '"'; i++) {
		prog->text[i] = prog->map[**index];
		**index += 1;
	}
	**index += 2;
}

void	engine_parsing_commands(obj_t **sprite, prog_t *prog, int *index)
{
	sfTime 	current_time = sfClock_getElapsedTime(prog->clock[4]);

	if (prog->delay == 1)
		return;
	if (sfTime_asMilliseconds(current_time) >= prog->delay) {
		engine_end(sprite, prog, &index);
		engine_spawn(sprite, prog, &index);
		engine_text(prog, &index);
		sfClock_restart(prog->clock[4]);
	}
	if (prog->map[*index] == '\0') {
		*index = 0;
		reset_map(prog);
	}
}