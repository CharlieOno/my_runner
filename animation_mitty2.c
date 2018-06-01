/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** functions to anime mitty
*/

#include "runner.h"

void	mitty_cast(int *start, obj_t *hero, obj_t *anim, int x)
{
	sfVector2f	pos = (sfVector2f) {anim->pos.x + x, anim->pos.y};

	sfSprite_setTextureRect(hero->obj, (sfIntRect) {0, 0, 60, 50});
	sfSprite_setPosition(anim->obj, pos);
	*start += 1;
}

void	mitty_cast2(int *start, obj_t *hero, obj_t *anim, int x)
{
	sfVector2f	pos = (sfVector2f) {anim->pos.x + x, anim->pos.y};

	sfSprite_setTextureRect(hero->obj, (sfIntRect) {0, 0, 60, 50});
	sfSprite_setPosition(anim->obj, pos);
	*start += 1;
}

void	reset_octopus(obj_t *anim, int *distance, int **hit, int *start)
{
	if (*distance == 1200) {
		sfSprite_setPosition(anim->obj, (sfVector2f) {-100, 450});
		**hit = 0;
		*distance = 200;
		*start = 0;
	}
}

void	mitty_octopus(obj_t *hero, obj_t *anim, sfClock *clock, int *hit)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	distance = 200;
	static int 	frame = 120;
	static int 	start = 0;

	distance = (*hit != 1) ? 200 : distance;
	start = (*hit != 1) ? 0 : start;
	if (sfTime_asMilliseconds(current_time) < 5 || *hit != 1)
		return;
	if (start < 4)
		mitty_cast2(&start, hero, anim, 60);
	sfSprite_setTextureRect(anim->obj, (sfIntRect) {frame, 120, 40, 39});
	sfSprite_move(anim->obj, (sfVector2f) {35, 0});
	distance += 40;
	frame += 40;
	frame = (frame == 240) ? 120 : frame;
	sfClock_restart(clock);
	reset_octopus(anim, &distance, &hit, &start);
}