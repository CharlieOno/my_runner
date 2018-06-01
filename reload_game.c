/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** reload functions to avoid calling setup functions
*/

#include "runner.h"

void 	reload_character_states(prog_t *prog)
{
	prog->state.hex[0] = 0;
	prog->state.hex[1] = 0;
	prog->state.hex[2] = 0;
	prog->state.hex[3] = 0;
	prog->state.mitty[0] = 0;
	prog->state.mitty[1] = 0;
	prog->state.mitty[2] = 0;
	prog->state.mitty[3] = 0;
	prog->state.rog[0] = 0;
	prog->state.rog[1] = 0;
	prog->state.rog[2] = 0;
	prog->state.rog[3] = 0;
}

void 	reload_characters(obj_t **sprite)
{
	sfVector2f	h_pos = (sfVector2f) {10, 500};
	sfVector2f	e_pos = (sfVector2f) {10, 450};

	sf_pos(sprite[10]->obj, h_pos);
	sf_pos(sprite[3]->obj, e_pos);
	sf_pos(sprite[7]->obj, e_pos);
	load_stats(sprite[3], "data/hex.dat");
	load_stats(sprite[7], "data/mitty.dat");
	load_stats(sprite[10], "data/rog.dat");
}

void 	reload_mob(obj_t **sprite)
{
	sfVector2f	c_pos = (sfVector2f) {-300, 500};

	for (int i = 0; i < NB_SPRITE; i++) {
		if (sprite[i]->type == MOB || sprite[i]->type == MOBANIM) {
			sf_pos(sprite[i]->obj, c_pos);
			update_hitbox(sprite[i], (sfVector2f) {-5, 0});
		}
	}
}

void	reload_anim(prog_t *prog, obj_t **sprite)
{
	sfVector2f	reset = (sfVector2f) {-999, -999};
	
	for (int i = 0; i < NB_SPRITE; i++) {
		if (sprite[i]->type != UI && prog->menu == 0)
			sf_pos(sprite[i]->obj, reset);
		if (sprite[i]->type == ANIM && sprite[i]->pos.x > 800)
			sf_pos(sprite[i]->obj, reset);
	}
}

void	reload_game(prog_t *prog, obj_t **sprite)
{
	reload_characters(sprite);
	reload_character_states(prog);
	reload_anim(prog, sprite);
	reload_mob(sprite);
	prog->state.win = 0;
	prog->state.defeated = 0;
	for (int i = 0; i < NB_MOB; i++)
		prog->state.mob[i] = 0;
	reset_map(prog);
	load_map("map/test.map", prog);
}