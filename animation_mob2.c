/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** mob animations functions part 2
*/

#include "runner.h"

void	reset_oldman(int *step, obj_t *sprt, int **state)
{
	if (*step == 50) {
		sfSprite_setPosition(sprt->obj, (sfVector2f) {-300, 470});
		**state = 0;
		*step = 0;
	}
}

void	mob_oldman(obj_t *sprt, sfClock *clock, int *state)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	step = 0;
	static int 	frame = 120;

	if (*state == 0) {
		step = 0;
		sf_pos(sprt->obj, (sfVector2f) {-120, 500});
		sprt->stats.hp = sprt->stats.maxhp;
	}
	if (sfTime_asSeconds(current_time) < 0.02 || *state != 1)
		return;
	sf_move(sprt->obj, (sfVector2f) {20, 0});
	sf_rect(sprt->obj, (sfIntRect) {frame, 400, 40, 40});
	frame = (frame == 200) ? 120 : frame + 40;
	step += 1;
	sfClock_restart(clock);
	reset_oldman(&step, sprt, &state);
}

void	reset_ufo(int *step, obj_t *sprt, int **state)
{
	if (*step == 80) {
		sfSprite_setPosition(sprt->obj, (sfVector2f) {-300, 470});
		**state = 0;
		*step = 0;
	}
}

void	fire_ufo(obj_t *sprt, obj_t *fire, sfClock *clock)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	state = 0;
	static int 	step = 0;
	sfVector2f	pos = sfSprite_getPosition(sprt->obj);

	if (state == 0) {
		sf_pos(fire->obj, (sfVector2f) {pos.x + 29, pos.y + 40});
		step = 0;
		state = 1;
	}
	if (sfTime_asSeconds(current_time) < 0.0002 || state != 1)
		return;
	sf_move(fire->obj, (sfVector2f) {0, 20});
	sfClock_restart(clock);
	step += 1;
	if (step == 15) {
		sf_pos(fire->obj, (sfVector2f) {-300, 470});
		state = 0;
		step = 0;
	}
}

void	mob_ufo(obj_t *sprt, obj_t *fire, sfClock* clock[2], int *state)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock[0]);
	static int 	step = 0;
	static int 	frame = 0;

	if (*state == 0) {
		step = 0;
		sf_pos(sprt->obj, (sfVector2f) {920, 245});
		sprt->stats.hp = sprt->stats.maxhp;
	}
	if (sfTime_asSeconds(current_time) < 0.002 || *state != 1)
		return;
	sf_move(sprt->obj, (sfVector2f) {-19, 0});
	sf_rect(sprt->obj, (sfIntRect) {frame, 0, 58, 35});
	frame = (frame == 638) ? 0 : frame + 58;
	step += 1;
	fire_ufo(sprt, fire, clock[1]);
	sfClock_restart(clock[0]);
	reset_ufo(&step, sprt, &state);
}