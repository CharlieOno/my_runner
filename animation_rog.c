/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** rog animations functions
*/

#include "runner.h"

void	reset_dash(obj_t *efct, int *frame, int *frame2, int **anim)
{
	if (*frame == 73 * 4 + 146) {
		**anim = 0;
		*frame = 146;
		*frame2 = 680;
		sfSprite_setPosition(efct->obj, (sfVector2f) {-100, 0});
	}
}

void	rog_dash(obj_t *hero, obj_t *efct, sfClock *clock, int *anim)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	int 		pos_x = hero->pos.x + 110;
	sfVector2f	pos = (sfVector2f) {pos_x, hero->pos.y + 30};
	static int 	frame = 146;
	static int 	frame2 = 680;

	if (*anim == 2 && frame2 >= 718)
		sfSprite_setPosition(efct->obj, pos);
	frame = (*anim != 2) ? 146 : frame;
	if (sfTime_asSeconds(current_time) < 0.15 || *anim != 2) {
		frame2 = 680;
		return;
	}
	sfSprite_setTextureRect(hero->obj, (sfIntRect) {frame, 723, 73, 53});
	sfSprite_setTextureRect(efct->obj, (sfIntRect) {frame2, 1002, 38, 30});
	frame += 73;
	frame2 += 38;
	sfClock_restart(clock);
	reset_dash(efct, &frame, &frame2, &anim);
}

void	rog_landing(obj_t *hero, int state)
{
	sfIntRect	rect = (sfIntRect) {395, 110, 51, 54};

	if (state != 31)
		return;
	sfSprite_setTextureRect(hero->obj, rect);
	sfSprite_move(hero->obj, (sfVector2f) {0, 15});
}

void 	rog_jump(obj_t *hero, sfClock *clock, int *anim)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	state = 0;

	if (sfTime_asSeconds(current_time) < 0.005 || *anim != 1) {
		state = 0;
		return;
	}
	state += 1;
	sfClock_restart(clock);
	rog_jumping_logic(hero, state);
	*anim = (state == 31) ? 0 : 1;
	rog_landing(hero, state);
	state = (state == 31) ? 0 : state;
}

void 	rog_walk(obj_t *hero, sfClock *clock, int *anim)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	frame = 395;

	if (sfTime_asSeconds(current_time) < 0.11 || *anim != 0)
		return;
	sfSprite_setTextureRect(hero->obj, (sfIntRect) {frame, 110, 52, 54});
	sfSprite_move(hero->obj, (sfVector2f) {-1, 0});
	frame += 52;
	sfClock_restart(clock);
	if (frame == 52 * 5 + 395) {
		sfSprite_move(hero->obj, (sfVector2f) {5, 0});
		frame = 395;
	}
}