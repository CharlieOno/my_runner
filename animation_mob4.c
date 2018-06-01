/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** animations functions mob part 4
*/

#include "runner.h"

void	reset_cannon(int *step, obj_t *sprt, int **state)
{
	if (*step == 120) {
		sfSprite_setPosition(sprt->obj, (sfVector2f) {-300, 470});
		**state = 0;
		*step = 0;
	}
}

void	fire_cannon(obj_t *sprt, obj_t *fire, sfClock *clock)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	state = 0;
	static int 	step = 0;
	sfVector2f	pos = sfSprite_getPosition(sprt->obj);

	if (state == 0) {
		sf_pos(fire->obj, (sfVector2f) {pos.x - 10, pos.y + 90});
		step = 0;
		state = 1;
	}
	if (sfTime_asSeconds(current_time) < 0.0001 || state != 1)
		return;
	sf_move(fire->obj, (sfVector2f) {-30, 30});
	sfClock_restart(clock);
	step += 1;
	if (step == 15) {
		sf_pos(fire->obj, (sfVector2f) {-300, 470});
		state = 0;
		step = 0;
	}
}

void	mob_cannon(obj_t *sprt, obj_t *fire, sfClock* clock[2], int *state)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock[0]);
	static int 	step = 0;

	if (*state == 0) {
		step = 0;
		sf_pos(sprt->obj, (sfVector2f) {800, 300});
		sprt->stats.hp = sprt->stats.maxhp;
	}
	if (sfTime_asSeconds(current_time) < 0.004 || *state != 1)
		return;
	sf_move(sprt->obj, (sfVector2f) {-16, -5});
	step += 1;
	fire_cannon(sprt, fire, clock[1]);
	sfClock_restart(clock[0]);
	reset_cannon(&step, sprt, &state);
}