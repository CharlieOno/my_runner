/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** functions to anime mitty character
*/

#include "runner.h"

void 	mitty_jump(obj_t *hero, sfClock *clock, int *anim)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	state = 0;

	state = (*anim != 1) ? 0 : state;
	if (sfTime_asSeconds(current_time) < 0.005 || *anim != 1)
		return;
	sfSprite_setTextureRect(hero->obj, (sfIntRect) {0, 55, 51, 46});
	state += 1;
	sfClock_restart(clock);
	if (state <= 16)
		sfSprite_move(hero->obj, (sfVector2f) {0, -15});
	else
		sfSprite_move(hero->obj, (sfVector2f) {0, 15});
	*anim = (state == 32) ? 0 : 1;
	state = (state == 32) ? 0 : state;
}

void 	mitty_slide(obj_t *hero, sfClock *clock, int *anim)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	frame = 54;

	if (*anim == 2)
		sfRectangleShape_setPosition(hero->hit,
		(sfVector2f) {-1938, 300});
	if (sfTime_asSeconds(current_time) < 0.12 || *anim != 2)
		return;
	sfSprite_setPosition(hero->obj, (sfVector2f) {hero->pos.x,
	hero->pos.y + 4});
	sfSprite_setTextureRect(hero->obj, (sfIntRect) {frame, 53, 49, 50});
	frame += (frame == 50 * 2 + 54) ? 50 * 3 + 6 : 50;
	sfClock_restart(clock);
	if (frame == 50 * 7 + 54 + 6) {
		sfSprite_setPosition(hero->obj, (sfVector2f)
		{hero->pos.x, hero->pos.y - 16});
		*anim = 0;
		frame = 54;
	}
}

void 	mitty_move(obj_t *hero, int speed)
{
	hero->pos = sfSprite_getPosition(hero->obj);
	if (sfKeyboard_isKeyPressed(sfKeyRight) && hero->pos.x < 730)
		sfSprite_move(hero->obj, (sfVector2f) {speed, 0});
	if (sfKeyboard_isKeyPressed(sfKeyLeft) && hero->pos.x > 0)
		sfSprite_move(hero->obj, (sfVector2f) {-speed * 1.4, 0});
}

void 	mitty_walk(obj_t *hero, sfClock *clock, int *anim)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	frame = 207;

	if (sfTime_asSeconds(current_time) < 0.11 || *anim != 0)
		return;
	sfSprite_setTextureRect(hero->obj, (sfIntRect) {frame, 0, 51, 55});
	frame += 51;
	sfClock_restart(clock);
	if (frame == 51 * 3 + 207)
		frame = 207;
}

void 	mitty_fireball(obj_t *hero, obj_t *anim, sfClock *clock, int *spell)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	frame = 0;
	static int 	distance = 0;
	static int 	start = 0;

	start = (*spell != 1) ? 0 : start;
	if (sfTime_asSeconds(current_time) < 0.002 || *spell != 1)
		return;
	if (start < 4)
		mitty_cast(&start, hero, anim, 60);
	sfSprite_setTextureRect(anim->obj, (sfIntRect) {frame, 49, 50, 50});
	sfSprite_move(anim->obj, (sfVector2f) {30, 0});
	frame += 50;
	frame = (frame == 50 * 8) ? 50 * 4 : frame;
	distance += 20;
	sfClock_restart(clock);
	*spell = (distance == 20 * 40) ? 0 : *spell;
	frame = (distance == 20 * 40) ? 0 : frame;
	start = (distance == 20 * 40) ? 0 : start;
	distance = (distance == 20 * 40) ? 0 : distance;
}