/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** animations functions for rog
*/

#include "runner.h"

void	rog_effect(obj_t *efct)
{
	static int 	frame = 680;

	sf_rect(efct->obj, (sfIntRect) {frame, 1002, 38, 30});
	frame += 38;
	if (frame == 756) {
		sf_pos(efct->obj, (sfVector2f) {-100, 0});
		frame = 680;
	}
}

void	reset_values_ice(int *frame, int *x, int **anim, obj_t *hero)
{
	if (*frame == 409) {
		*frame = 75;
		*x = 70;
		sf_move(hero->obj, (sfVector2f) {0, 30});
		**anim = 0;
	}
}

void	rog_icehit(obj_t *hero, sfClock *clock, int *anim)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	frame = 75;
	static int 	x = 70;

	if (*anim == 1 && frame < 312) {
		sf_rect(hero->obj, (sfIntRect) {frame, 340, x, 74});
	}
	if (sfTime_asSeconds(current_time) < 0.15 || *anim != 1)
		return;
	frame += (frame <= 70 * 1 + 75) ? 70 : 97;
	x = (frame <= 70 * 1 + 75) ? 70 : 94;
	sfClock_restart(clock);
	reset_values_ice(&frame, &x, &anim, hero);
}

void	reset_values_fire(int *frame, int *x, int **anim, obj_t *hero)
{
	if (*frame >= 624) {
		*frame = 320;
		*x = 70;
		sf_move(hero->obj, (sfVector2f) {0, 30});
		**anim = 0;
	}
}

void	rog_firehit(obj_t *hero, sfClock *clock, int *anim)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	frame = 320;
	static int 	x = 61;

	if (*anim == 2 && frame < 549) {
		sf_rect(hero->obj, (sfIntRect) {frame, 425, x, 74});
	}
	if (sfTime_asSeconds(current_time) < 0.15 || *anim != 2)
		return;
	frame += (frame == 320) ? 61 : 93;
	x = (frame == 320) ? 93 : 83;
	sfClock_restart(clock);
	reset_values_fire(&frame, &x, &anim, hero);
}