/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** hex character animations functions
*/

#include "runner.h"

void	hex_cast(int *start, obj_t *hero, obj_t *anim, int offset)
{
	sfVector2f	pos = (sfVector2f) {anim->pos.x + offset, anim->pos.y};

	sfSprite_setTextureRect(hero->obj, (sfIntRect) {170, 120, 60, 60});
	sfSprite_setPosition(anim->obj, pos);
	*start += 1;
}

void	hex_hit(obj_t *hero, obj_t *anim, sfClock *clock, int *hit)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	distance = 200;
	static int 	start = 0;

	if (sfTime_asSeconds(current_time) < 0.005 || *hit != 1)
		return;
	if (start < 4)
		hex_cast(&start, hero, anim, 60);
	sfSprite_move(anim->obj, (sfVector2f) {16, 0});
	distance += 25;
	sfClock_restart(clock);
	if (distance == 600) {
		sfSprite_setPosition(anim->obj, (sfVector2f) {-100, 450});
		*hit = 0;
		distance = 200;
		start = 0;
	}
}

void	hex_shield(obj_t *hero, obj_t *anim, sfClock *clock, int *shield)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	frame = 0;

	if (*shield == 1) {
		sfSprite_setPosition(anim->obj, 
		(sfVector2f) {hero->pos.x - 60, hero->pos.y - 40});
	}
	if (frame >= 408)
		sfSprite_setPosition(anim->obj, (sfVector2f) {-300, 450});
	if (sfTime_asSeconds(current_time) < 0.10 || *shield != 1)
		return;
	sfSprite_setTextureRect(anim->obj, (sfIntRect) {frame, 0, 102, 100});
	frame += 102;
	sfClock_restart(clock);
	*shield = (frame == 3060) ? 0 : 1;
	frame = (frame == 3060) ? 0 : frame;
}