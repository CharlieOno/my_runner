/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** setup functions for my_runner
*/

#include "runner.h"

void 	setup2(obj_t **sprite, prog_t *prog)
{
	setup_hitbox_characters(sprite);
	setup_hitbox_characters2(sprite);
	setup_hitbox_mob1(sprite);
	setup_hitbox_mob2(sprite);
	setup_character_stats(sprite);
	setup_menu(sprite);
	setup_menu2(sprite);
	setup_gameui(sprite);
	setup_pause(sprite);
	setup_general_sounds(prog);
	setup_spell_sounds(prog);
}

void 	setup(obj_t **sprite, prog_t *prog)
{
	setup_program(prog);
	setup_parralax(sprite);
	setup_character_states(prog);
	setup_engine(prog);
	setup_mob_part1(sprite);
	setup_mob_part2(sprite);
	setup_mob_part3(sprite);
	setup_hex(sprite);
	setup_mitty(sprite);
	setup_rog(sprite);
	setup2(sprite, prog);
}

void 	setup_engine(prog_t *prog)
{
	prog->state.mob = malloc(sizeof(int) * NB_SPRITE);
	for (int i = 0; i < NB_SPRITE; i++)
		prog->state.mob[i] = 0;
	init_map(prog);
	reset_map(prog);
	load_map("map/test.map", prog);
}

void 	setup_parralax(obj_t **sprite)
{
	sfVector2f	pos = (sfVector2f) {0, 0};
	sfIntRect 	rect = (sfIntRect) {0, 0, 352, 192};

	sprite[0] = create_object("img/layer1.png", pos, rect, PARRALAX);
	sfSprite_setScale(sprite[0]->obj, (sfVector2f) {3.125, 3.125});
	sprite[1] = create_object("img/layer2.png", pos, rect, PARRALAX);
	sfSprite_setScale(sprite[1]->obj, (sfVector2f) {3.125, 3.125});
	sprite[2] = create_object("img/layer3.png", pos, rect, PARRALAX);
	sfSprite_setScale(sprite[2]->obj, (sfVector2f) {3.125, 3.125});
}

void 	setup_program(prog_t *prog)
{
	prog->clock = malloc(sizeof(sfClock*) * NB_CLOCK);
	prog->mode = (sfVideoMode) {800, 600, 32};
	for (int i = 0; i < NB_CLOCK; i++)
		prog->clock[i] = sfClock_create();
	prog->delay = 0;
	prog->menu = 0;
	prog->text = malloc(sizeof(char) * 255);
	prog->window = sfRenderWindow_create(prog->mode, "MyRunner",
	sfDefaultStyle, NULL);
	prog->charac = 1;
	prog->state.mode = 0;
	sfRenderWindow_setFramerateLimit(prog->window, 30);
}