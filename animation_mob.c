/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** functions to animate monsters
*/

#include "runner.h"

void	reset_geisha(int *step, obj_t *sprt, int **state)
{
	if (*step == 50) {
		sfSprite_setPosition(sprt->obj, (sfVector2f) {-300, 470});
		**state = 0;
		*step = 0;
	}
}

void	mob_geisha(obj_t *sprt, sfClock *clock, int *state)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	step = 0;
	static int 	frame = 0;

	if (*state == 0) {
		step = 0;
		sf_pos(sprt->obj, (sfVector2f) {920, 500});
		sprt->stats.hp = sprt->stats.maxhp;
	}
	if (sfTime_asSeconds(current_time) < 0.02 || *state != 1)
		return;
	sf_move(sprt->obj, (sfVector2f) {-20, 0});
	sf_rect(sprt->obj, (sfIntRect) {frame, 352, 40, 45});
	frame = (frame == 80) ? 0 : frame + 40;
	step += 1;
	sfClock_restart(clock);
	reset_geisha(&step, sprt, &state);
}

void	mob_big(obj_t *big, sfClock *clock, int *state)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	step = 0;

	if (*state == 0) {
		step = 0;
		sf_pos(big->obj, (sfVector2f) {920, 455});
		big->stats.hp = big->stats.maxhp;
	}
	if (sfTime_asSeconds(current_time) < 0.002 || *state != 1)
		return;
	sf_move(big->obj, (sfVector2f) {-8, 0});
	step += 1;
	sfClock_restart(clock);
	if (step == 240) {
		sfSprite_setPosition(big->obj, (sfVector2f) {-300, 470});
		*state = 0;
		step = 0;
	}
}

void	mob_truck(obj_t *car, sfClock *clock, int *state)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	step = 0;

	if (*state == 0) {
		step = 0;
		sf_pos(car->obj, (sfVector2f) {920, 485});
		car->stats.hp = car->stats.maxhp;
	}
	if (sfTime_asSeconds(current_time) < 0.002 || *state != 1)
		return;
	sf_move(car->obj, (sfVector2f) {-15, 0});
	step += 1;
	sfClock_restart(clock);
	if (step == 80) {
		sfSprite_setPosition(car->obj, (sfVector2f) {-300, 470});
		*state = 0;
		step = 0;
	}
}

void	mob_car(obj_t *car, sfClock *clock, int *state)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	step = 0;

	if (*state == 0) {
		step = 0;
		sf_pos(car->obj, (sfVector2f) {920, 480});
		car->stats.hp = car->stats.maxhp;
	}
	if (sfTime_asSeconds(current_time) < 0.002 || *state != 1)
		return;
	sf_move(car->obj, (sfVector2f) {-15, 0});
	step += 1;
	sfClock_restart(clock);
	if (step == 80) {
		sfSprite_setPosition(car->obj, (sfVector2f) {-300, 470});
		*state = 0;
		step = 0;
	}
}