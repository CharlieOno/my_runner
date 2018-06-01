/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** functions to handle all the animations
*/

#include "runner.h"

void	rog_sword_hitbox(prog_t *prog, obj_t **sprite)
{
	sfVector2f	pos;

	if (prog->state.rog[1] != 0 || prog->state.rog[2] == 1 ||
		prog->state.rog[0] == 2) {
		sprite[10]->pos = sfSprite_getPosition(sprite[10]->obj);
		pos.x = sprite[10]->pos.x + 100;
		pos.y = sprite[10]->pos.y;
		sfRectangleShape_setPosition(sprite[11]->hit, pos);
	} else {
		sfRectangleShape_setPosition(sprite[11]->hit, (sfVector2f)
		{-900, 800});
	}
}

void	dead_animation(prog_t *prog, obj_t *sprite, int *state)
{
	if (sprite->type != CHARACTER && sprite->type != MOB)
		return;
	if (sprite->stats.hp > 0) {
		sfSprite_setColor(sprite->obj, (sfColor) {255, 255, 255, 255});
		*state = 255;
		return;
	}
	sfRectangleShape_setPosition(sprite->hit, (sfVector2f) {-2938, 300});
	sfSprite_setColor(sprite->obj, (sfColor) {255, 255, 255, *state});
	*state -= 15;
	if (*state == 0) {
		prog->menu = (sprite->type == CHARACTER) ? 3 : prog->menu;
		sf_pos(sprite->obj, (sfVector2f) {-3000, -3000});
		prog->delay = (prog->delay == 1) ? 0 : prog->delay;
	}
}

void	mob_animation2(prog_t *prog, obj_t **sprite)
{
	sfClock	*clock_array2[2];
	sfClock	*clock_array3[2];

	clock_array2[0] = prog->clock[13];
	clock_array2[1] = prog->clock[14];
	clock_array3[0] = prog->clock[15];
	clock_array3[1] = prog->clock[16];
	mob_yeti(sprite[40], sprite[41], clock_array2, &prog->state.mob[6]);
	mob_cannon(sprite[42], sprite[43], clock_array3, &prog->state.mob[7]);
	update_hitbox(sprite[40], (sfVector2f) {0, 0});
	update_hitbox(sprite[41], (sfVector2f) {0, 0});
	update_hitbox(sprite[42], (sfVector2f) {0, 0});
	update_hitbox(sprite[43], (sfVector2f) {0, 0});
}

void	mob_animation(prog_t *prog, obj_t **sprite)
{
	sfClock	*clock_array[2];

	clock_array[0] = prog->clock[11];
	clock_array[1] = prog->clock[12];
	mob_truck(sprite[12], prog->clock[5], &prog->state.mob[0]);
	mob_car(sprite[13], prog->clock[6], &prog->state.mob[1]);
	mob_big(sprite[34], prog->clock[7], &prog->state.mob[2]);
	mob_geisha(sprite[35], prog->clock[8], &prog->state.mob[3]);
	mob_oldman(sprite[36], prog->clock[9], &prog->state.mob[4]);
	mob_ufo(sprite[38], sprite[39], clock_array, &prog->state.mob[5]);
	update_hitbox(sprite[12], (sfVector2f) {-5, 0});
	update_hitbox(sprite[13], (sfVector2f) {-5, 5});
	update_hitbox(sprite[34], (sfVector2f) {5, 5});
	update_hitbox(sprite[35], (sfVector2f) {0, 0});
	update_hitbox(sprite[36], (sfVector2f) {0, 0});
	update_hitbox(sprite[38], (sfVector2f) {0, 0});
	update_hitbox(sprite[39], (sfVector2f) {0, 0});
	mob_animation2(prog, sprite);
}

void	game_animations(prog_t *prog, obj_t **sprite)
{
	parralax_right(sprite[2], prog->window, 1.311);
	parralax_right(sprite[1], prog->window, 3.733);
	parralax_right(sprite[0], prog->window, 6.144);
	hex_animation(prog, sprite);
	mitty_animation(prog, sprite);
	rog_animation(prog, sprite);
	mob_animation(prog, sprite);
}