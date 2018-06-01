/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** call functions loop functions
*/

#include "runner.h"

void	cchoice_loop(obj_t **sprite, prog_t *prog, sfEvent event)
{
	static int	select = 0;
	static int 	selected = 0;

	if (prog->menu != 4)
		return;
	hex_walk(sprite[3], prog->clock[0], &prog->state.hex[0]);
	mitty_walk(sprite[7], prog->clock[1], &prog->state.mitty[0]);
	rog_walk(sprite[10], prog->clock[2], &prog->state.rog[0]);
	cchoice_draw_obj(prog, sprite);
	alpha_characters(sprite, select);
	cchoice_change(sprite, prog, select, &selected);
	cchoice_events(prog, event, &select, &selected);
	if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
		reload_anim(prog, sprite);
		prog->menu = 0;
	}
}

void	mchoice_loop(obj_t **sprite, prog_t *prog, sfEvent event)
{
	static int 	select = 0;
	static int 	selected = 0;

	if (prog->menu != 5)
		return;
	mchoice_draw_obj(prog, sprite, select);
	mchoice_change(sprite, prog, select, &selected);
	mchoice_events(prog, event, &select, &selected);
}