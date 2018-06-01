/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** menu handling functions
*/

#include "runner.h"

void	menu_loop(obj_t **sprite, prog_t *prog, sfEvent event)
{
	static int	select = 0;
	static int 	selected = 0;

	if (prog->menu != 0)
		return;
	game_engine(prog, sprite);
	menu_change(prog, sprite, select, &selected);
	menu_events(prog, event, &select, &selected);
	menu_draw_obj(prog, sprite, select);
	sound_menu(prog);
}

void	game_loop(obj_t **sprite, prog_t *prog, sfEvent event)
{
	if (prog->menu != 1)
		return;
	game_events(prog, sprite, event);
	game_animations(prog, sprite);
	game_engine(prog, sprite);
	game_draw_obj(prog, sprite);
	sound_game(prog);
	sound_character(prog);
}

void	pause_loop(obj_t **sprite, prog_t *prog, sfEvent event)
{
	static int 	select = 0;
	static int 	selected = 0;

	if (prog->menu != 2)
		return;
	pause_change(sprite, prog, select, &selected);
	pause_events(prog, event, &select, &selected);
	pause_draw_obj(prog, sprite, select);
}

void	win_loop(obj_t **sprite, prog_t *prog, sfEvent event)
{
	if (prog->menu != 3)
		return;
	win_events(prog, event);
	win_draw_obj(prog, sprite);
}

void	menu_handling(obj_t **sprite, prog_t *prog, sfEvent event)
{
	menu_loop(sprite, prog, event);
	game_loop(sprite, prog, event);
	pause_loop(sprite, prog, event);
	win_loop(sprite, prog, event);
	cchoice_loop(sprite, prog, event);
	mchoice_loop(sprite, prog, event);
}