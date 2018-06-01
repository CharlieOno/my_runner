/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** hex character animations functions
*/

#include "runner.h"

void 	hex_jump(obj_t *hero, sfClock *clock, int *anim)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	state = 0;

	state = (*anim != 1) ? 0 : state;
	if (sfTime_asSeconds(current_time) < 0.03 || *anim != 1)
		return;
	sfSprite_setTextureRect(hero->obj, (sfIntRect) {-1, 120, 60, 60});
	state += 1;
	sfClock_restart(clock);
	if (state <= 16)
		sfSprite_move(hero->obj, (sfVector2f) {0, -15});
	else
		sfSprite_move(hero->obj, (sfVector2f) {0, 15});
	*anim = (state == 32) ? 0 : 1;
	state = (state == 32) ? 0 : state;
}

void 	hex_walk(obj_t *hero, sfClock *clock, int *anim)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	frame = -1;

	if (sfTime_asSeconds(current_time) < 0.11 || *anim != 0)
		return;
	sfSprite_setTextureRect(hero->obj, (sfIntRect) {frame, 60, 60, 60});
	frame += 60;
	sfClock_restart(clock);
	if (frame == 60 * 6 + -1)
		frame = -1;
}

void 	hex_slide(obj_t *hero, sfClock *clock, int *anim)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	frame = 170;

	if (sfTime_asSeconds(current_time) < 0.03 || *anim != 2)
		return;
	frame += 60;
	sf_move(hero->obj, (sfVector2f) {30, 0});
	sfSprite_setTextureRect(hero->obj, (sfIntRect) {frame, -10, 60, 60});
	sfClock_restart(clock);
	if (frame == 350) {
		*anim = 0;
		frame = 170;
	}
}

void 	hex_shock(obj_t *hero, obj_t *anim, sfClock *clock, int *spell)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	frame = 230;
	static int 	distance = 230;
	static int 	start = 0;

	if (sfTime_asSeconds(current_time) < 0.03 || *spell != 1)
		return;
	if (start < 4)
		hex_cast(&start, hero, anim, 40);
	sfSprite_setTextureRect(anim->obj, (sfIntRect) {frame, 52, 30, 52});
	sfSprite_move(anim->obj, (sfVector2f) {20, 0});
	frame += (frame < 380) ? 25 : 0;
	distance += 25;
	sfClock_restart(clock);
	if (distance == 1405) {
		*spell = 0;
		frame = 230;
		distance = 230;
		start = 0;
	}
}

void 	hex_move(obj_t *hero, int speed)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight) && hero->pos.x < 740)
		sfSprite_move(hero->obj, (sfVector2f) {speed, 0});
	if (sfKeyboard_isKeyPressed(sfKeyLeft) && hero->pos.x > 0)
		sfSprite_move(hero->obj, (sfVector2f) {-speed * 1.4, 0});
}