/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** engine infinite play
*/

#include "runner.h"

void	engine_randspawn(prog_t *prog, obj_t **sprite)
{
	int 	charac_id = 3;
	int 	random = rand() % NB_MOB;
	int 	level = 1;

	charac_id = (prog->charac == 1) ? 7 : charac_id;
	charac_id = (prog->charac == 2) ? 10 : charac_id;
	level = sprite[charac_id]->stats.lvl;
	if (charac_id == 10 && random == 6)
		return;
	if (prog->state.mob[random] != 1) {
		prog->state.mob[random] = 1;
		generate_mob_stats(sprite, random, level);
		prog->delay = 1600;
		sfClock_restart(prog->clock[4]);
	}
}

void	engine_infinite(prog_t *prog, obj_t **sprite)
{
	sfTime 	current_time = sfClock_getElapsedTime(prog->clock[4]);

	if (prog->delay == 1)
		return;
	if (sfTime_asMilliseconds(current_time) >= prog->delay)
		engine_randspawn(prog, sprite);
}