/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** animations functions for rog - part 3
*/

#include "runner.h"

void 	rog_move(obj_t *hero, int speed)
{
	hero->pos = sfSprite_getPosition(hero->obj);
	if (sfKeyboard_isKeyPressed(sfKeyRight) && hero->pos.x < 730)
		sfSprite_move(hero->obj, (sfVector2f) {speed, 0});
	if (sfKeyboard_isKeyPressed(sfKeyLeft) && hero->pos.x > 0)
		sfSprite_move(hero->obj, (sfVector2f) {-speed * 1.4, 0});
}

void	rog_buff(obj_t *hero, sfClock *clock, int *anim)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	step = 0;

	if (*anim == 1)
		sf_rect(hero->obj, (sfIntRect) {12, 104, 57, 44});
	if (sfTime_asSeconds(current_time) < 0.06 || *anim != 1)
		return;
	sf_rect(hero->obj, (sfIntRect) {1215, 980, 48, 52});
	step += 1;
	sfClock_restart(clock);
	if (step == 5) {
		step = 0;
		*anim = 0;
	}
}

void	reset_smash(obj_t *hero, int *step, int *frame, int **anim)
{
	if (*frame == 774 + 132) {
		*step = 0;
		*frame = 510;
		sf_move(hero->obj, (sfVector2f) {0, 60});
		**anim = 0;
	}
}

void	rog_smash(obj_t *hero, sfClock *clock, int *anim)
{
	sfTime 	current_time = sfClock_getElapsedTime(clock);
	static int 	frame = 510;
	static int 	x = 66;
	static int 	step = 0;

	if (*anim == 1 && frame < 774)
		sf_rect(hero->obj, (sfIntRect) {frame, 332, x, 76});
	if (sfTime_asSeconds(current_time) < 0.06 || *anim != 1)
		return;
	(step < 3) ? sf_move(hero->obj, (sfVector2f) {20, 10}) :
	sf_move(hero->obj, (sfVector2f) {20, -10});
	step += 1;
	frame += 66;
	x = (frame == 708) ? 76 : 66;
	sfClock_restart(clock);
	x = (frame == 774 + 132) ? 66 : x;
	reset_smash(hero, &step, &frame, &anim);
}

void	rog_jumping_logic(obj_t *hero, int state)
{
	sfIntRect	rect = (sfIntRect) {715, 82, 54, 72};
	sfIntRect	rect2 = (sfIntRect) {770, 82, 54, 72};

	if (state <= 16) {
		sfSprite_setTextureRect(hero->obj, rect);
		sfSprite_move(hero->obj, (sfVector2f) {0, -15});
	} else {
		sfSprite_setTextureRect(hero->obj, rect2);
		sfSprite_move(hero->obj, (sfVector2f) {0, 15});
	}
}