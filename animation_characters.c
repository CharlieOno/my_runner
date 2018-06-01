/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** call animations for characters
*/

#include "runner.h"

void	hex_hitbox(prog_t *prog, obj_t **sprite)
{
	sfRectangleShape 	*hit = sprite[3]->hit;

	if (prog->state.hex[0] == 2) {
		sfRectangleShape_setSize(hit, (sfVector2f) {110, 60});
		update_hitbox(sprite[3], (sfVector2f) {4, 60});
	} else {
		sfRectangleShape_setSize(hit, (sfVector2f) {60, 130});
		update_hitbox(sprite[3], (sfVector2f) {4, 0});
	}
	update_hitbox(sprite[4], (sfVector2f) {10, 30});
	update_hitbox(sprite[5], (sfVector2f) {0, 0});
	update_hitbox(sprite[6], (sfVector2f) {22, 22});
}

void	hex_animation(prog_t *prog, obj_t **sprite)
{
	if (prog->charac != 0)
		return;
	hex_walk(sprite[3], prog->clock[0], &prog->state.hex[0]);
	hex_jump(sprite[3], prog->clock[0], &prog->state.hex[0]);
	hex_slide(sprite[3], prog->clock[0], &prog->state.hex[0]);
	hex_shock(sprite[3], sprite[4], prog->clock[1], &prog->state.hex[1]);
	hex_hit(sprite[3], sprite[5], prog->clock[2], &prog->state.hex[2]);
	hex_shield(sprite[3], sprite[6], prog->clock[3],
	&prog->state.hex[3]);
	hex_move(sprite[3], 8);
	hex_hitbox(prog, sprite);
}

void	mitty_animation(prog_t *prog, obj_t **sprite)
{
	if (prog->charac != 1)
		return;
	mitty_walk(sprite[7], prog->clock[0], &prog->state.mitty[0]);
	mitty_jump(sprite[7], prog->clock[0], &prog->state.mitty[0]);
	mitty_fireball(sprite[7], sprite[8], prog->clock[1],
	&prog->state.mitty[1]);
	mitty_octopus(sprite[7], sprite[9], prog->clock[2],
	&prog->state.mitty[2]);
	mitty_move(sprite[7], 7);
	update_hitbox(sprite[8], (sfVector2f) {25, 0});
	update_hitbox(sprite[9], (sfVector2f) {0, 0});
	if (prog->state.mitty[0] == 2)
		update_hitbox(sprite[7], (sfVector2f) {1000, 1000});
	if (prog->state.mitty[0] != 2)
		update_hitbox(sprite[7], (sfVector2f) {15, 0});
	mitty_slide(sprite[7], prog->clock[0], &prog->state.mitty[0]);
}

void	rog_hitbox(prog_t *prog, obj_t **sprite)
{
	update_hitbox(sprite[10], (sfVector2f) {20, 0});
	rog_sword_hitbox(prog, sprite);
	if (prog->state.rog[1] != 0)
		update_hitbox(sprite[10], (sfVector2f) {20, 30});
	if (prog->state.rog[2] == 1)
		update_hitbox(sprite[10], (sfVector2f) {20, 50});
	if (prog->state.rog[0] == 1)
		update_hitbox(sprite[10], (sfVector2f) {13, 30});
}

void	rog_animation(prog_t *prog, obj_t **sprite)
{
	if (prog->charac != 2)
		return;
	rog_walk(sprite[10], prog->clock[0], &prog->state.rog[0]);
	rog_jump(sprite[10], prog->clock[0], &prog->state.rog[0]);
	rog_dash(sprite[10], sprite[11], prog->clock[0], &prog->state.rog[0]);
	rog_icehit(sprite[10], prog->clock[1], &prog->state.rog[1]);
	rog_firehit(sprite[10], prog->clock[1], &prog->state.rog[1]);
	rog_smash(sprite[10], prog->clock[2], &prog->state.rog[2]);
	rog_buff(sprite[10], prog->clock[3], &prog->state.rog[3]);
	rog_move(sprite[10], 9);
	rog_hitbox(prog, sprite);
}