/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** main file for engine
*/

#include "runner.h"

int	*default_state(void)
{
	int	*state = malloc(sizeof(int) * NB_SPRITE);

	for (int i = 0; i < NB_SPRITE; i++)
		state[i] = 255;
	return (state);
}

void	engine_deaths(prog_t *prog, obj_t **sprite)
{
	static int	*state = NULL;

	state = (state == NULL) ? default_state() : state;
	for (int i = 0; i < NB_SPRITE; i++) {
		dead_animation(prog, sprite[i], &state[i]);
		if (state[i] == 240)
			sfSound_play(prog->sound[4]);
		if (state[i] == 240 && sprite[i]->type == CHARACTER) {
			save_stats(sprite[3], "data/hex.dat");
			save_stats(sprite[7], "data/mitty.dat");
			save_stats(sprite[10], "data/rog.dat");
		}
		add_exp(prog, sprite, &state[i], sprite[i]);
	}
}

void	engine_hit(int *state, obj_t *sprite)
{
	int		value = 255;
	sfColor 	color = sfSprite_getColor(sprite->obj);

	for (int i = 0; i < NB_SPRITE; i++)
		value = (state[i] == 1) ? 0 : value;
	color = (sfColor) {color.r, value, value, color.a};
	sfSprite_setColor(sprite->obj, color);
}

void	engine_generate_stats(prog_t *prog, obj_t **sprite)
{
	switch (prog->charac) {
		case 0:
			check_level_up(prog, sprite[3]);
			update_spell_dmg(sprite[3], sprite[4]);
			update_spell_dmg(sprite[3], sprite[5]);
			break;
		case 1:
			check_level_up(prog, sprite[7]);
			update_spell_dmg(sprite[7], sprite[8]);
			update_spell_dmg(sprite[7], sprite[9]);
			break;
		case 2:
			check_level_up(prog, sprite[10]);
			update_spell_dmg(sprite[10], sprite[11]);
			break;
	}
}

void	game_engine(prog_t *prog, obj_t **sprite)
{
	static int 	index = 0;

	if (prog->menu == 2)
		return;
	if (prog->menu != 1) {
		prog->delay = 0;
		index = 0;
		return;
	}
	engine_deaths(prog, sprite);
	engine_collision(prog, sprite);
	engine_generate_stats(prog, sprite);
	if (prog->state.mode == 1) {
		engine_infinite(prog, sprite);
		return;
	}
	engine_parsing_commands(sprite, prog, &index);
}