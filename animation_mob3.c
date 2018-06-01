/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** mob animations part 3
*/

#include "runner.h"

void	reset_yeti(int *start, obj_t *yeti, int **state)
{
	if (yeti->stats.hp <= 0) {
		sf_rect(yeti->obj, (sfIntRect) {0, 280, 120, 80});
		sfSprite_setPosition(yeti->obj, (sfVector2f) {-300, 470});
		**state = 0;
		*start = 0;
	}
}

void	fire_yeti(obj_t *sprt, obj_t *fire, sfClock *clock)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	state = 0;
	static int 	step = 0;
	sfVector2f	pos = sfSprite_getPosition(sprt->obj);

	if (state == 0) {
		sf_pos(fire->obj, (sfVector2f) {pos.x + 50, pos.y + 90});
		step = 0;
		state = 1;
	}
	if (sfTime_asSeconds(current_time) < 0.0002 || state != 1)
		return;
	sf_move(fire->obj, (sfVector2f) {-20, 0});
	sfClock_restart(clock);
	step += 1;
	if (step == 50) {
		sf_pos(fire->obj, (sfVector2f) {-300, 470});
		state = 0;
		step = 0;
	}
}

void	mob_yeti(obj_t *yeti, obj_t *fire, sfClock* clock[2], int *state)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock[0]);
	static int 	start = 0;

	if (*state == 0) {
		start = 0;
		sf_pos(fire->obj, (sfVector2f) {-100, 3784});
		sf_pos(yeti->obj, (sfVector2f) {800, 420});
		yeti->stats.hp = yeti->stats.maxhp;
	}
	if (sfTime_asSeconds(current_time) < 0.002 || *state != 1)
		return;
	sfClock_restart(clock[0]);
	if (start < 15) {
		start += 1;
		sf_move(yeti->obj, (sfVector2f) {-15, 0});
		return;
	}
	sf_rect(yeti->obj, (sfIntRect) {120, 280, 120, 80});
	fire_yeti(yeti, fire, clock[1]);
	reset_yeti(&start, yeti, &state);
}